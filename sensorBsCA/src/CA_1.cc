
#include "CA_1.h"

#include<cstring>
#include<sstream>
#include<string>

#include <iostream>
#include <fstream>

Define_Module(CA_1);

CA_1::CA_1()
{
    state=OFF;
    curDenyNum=0;

    for(int i=0;i<maxTrustBs;i++)
        trustBsArr[i]=-1;

    selfstartMsg=new cMessage("selfstartMsg");
    selfRegiste=new cMessage("selfRegiste");
    certiRequest=new certiMessage("certiRequest");
//    CertiReply=new certiMessage("CertiReply");
    rejectMsg=new cMessage("rejectMsg");
    askCaMsg=new askRenewMessage("askCaMsg");
    caReply=new replyRenewMessage("caReply");


    curTrustNum=0;
}

CA_1::~CA_1()
{

}

void CA_1::initialize()
{
    std::ifstream in("../simulations/CA_1_Info.txt");
    CA1_count++;

    int xtemp;
    int ytemp;
    char s[500]={};
    for(int i=0;i<CA1_count;i++){
        in.getline(s,sizeof(s));
    }
    std::stringstream word(s);
    word >> uuid;
    word >> xtemp;
    word >> ytemp;
    word >> sign_public;
    word >> sign_private;
    word >> upper_index;
    word >> upper_uuid;

    setX(xtemp);
    setY(ytemp);
    cDisplayString &dspy = getDisplayString();
    dspy.setTagArg("p",0,x);
    dspy.setTagArg("p",1,y);

    scheduleAt(uniform(0,par("offTime")),selfstartMsg);

    caIndex=upper_index;


    std::ifstream in1("../simulations/CA_1_Trust_Info.txt");
    int index;
    curTrustNum = 0;
    while(in1.getline(s,sizeof(s))){
        std::stringstream word(s);
        word >> index;
        //ev << 'index:' << index << ',';
        if(index == CA1_count - 1){
            word >> trustBsArr[curTrustNum];
            ev << trustBsArr[curTrustNum] << " ";
            curTrustNum++;
        }
    }
    ev << std::endl;

//    in1.getline(s,sizeof(s));
//    std::stringstream word1(s);
//    word1 >> index;
//    ev << "(" <<index << ")";
//    word1 >> index;
//    ev << "(" <<index << ")";
//    ev << "[";
//
//    in1.getline(s,sizeof(s));
//    std::stringstream word2(s);
//    word2 >> index;
//    ev << "(" <<index << ")";
//    word2 >> index;
//    ev << "(" <<index << ")";
//    ev << "[";
//
//
//    for(int i = 0; i < curTrustNum; i++){
//        ev << trustBsArr[curTrustNum];
//    }
//    ev << "]";
}

void CA_1::handleMessage(cMessage *msg)
{
    if(strcmp(msg->getName(), "selfstartMsg") == 0)
    {
        if(state==OFF)
        {
            gotoUnregi();
            delete msg;
        }
    }
    else if(strcmp(msg->getName(), "selfRegiste") == 0) //generate certi wanted event
    {
       if(state==UNREGI)
       {
         certiRequest=new certiMessage("certiRequest");
         certiRequest->setSrc_index(par("c1Index")); //婧愮
         send(certiRequest,"ca1ToCa2$o",caIndex);
         delete msg;
       }
       else
         delete msg;

    }
    else if(strcmp(msg->getName(), "certiRequest")==0)  //鏀跺埌bs鐨勮瘉涔﹁姹�
    {
        certiRequest=check_and_cast<certiMessage*>(msg);
        int deIndex=certiRequest->getSrc_index();
        ev << "(" << deIndex << ")" ;
        if(istrust(deIndex))  //鏄兘璁よ瘉鐨刡s
        {
            certiReply=new certiMessage("certiReply");
//            certiReply->setSig_srcid((sigCerti.src_id).c_str());
//            certiReply->setSig_srccomkey((sigCerti.src_comkey).c_str());
//            certiReply->setSig_CAid((sigCerti.CA_id).c_str());
//            certiReply->setSig_CAsig((sigCerti.CA_sig).c_str());
            send(certiReply,"ca1ToBs$o",deIndex);
        }
        else //鍚﹀垯鎷掔粷
        {
            rejectMsg=new cMessage("rejectMsg");
            send(rejectMsg,"ca1ToBs$o",deIndex);
        }

        delete msg;
    }
    else if(strcmp(msg->getName(), "certiReply") == 0)//鏀跺埌ca2鍥炲,have been verified by CA2
    {
        certiReply=check_and_cast<certiMessage*>(msg);
        sigCerti.src_id=certiReply->getSig_srcid();
        sigCerti.src_comkey=certiReply->getSig_srccomkey();
        sigCerti.CA_id=certiReply->getSig_CAid();
        sigCerti.CA_sig=certiReply->getSig_CAsig();
        gotoRegiste();
        delete msg;
    }
    else if(strcmp(msg->getName(),"askCaMsg")==0) //asked by lower bs
    {
       askCaMsg=check_and_cast<askRenewMessage*>(msg);
       int srcIndex=askCaMsg->getBs_search_index(); //the judged node
       int bs_sendIndex=askCaMsg->getBs_src_index();  //the answerd node
       if(istrust(srcIndex))
       {
         ev<<"CA1"<<" get askCaMsg and verifying bs["<<srcIndex<<"]";
         delete msg;
         caReply=new replyRenewMessage("caReply");
         caReply->setBs_src_index(bs_sendIndex);
         caReply->setTrust(true);  //say trust to lower bs
         caReply->setBs_search_index(srcIndex);
         caReply->setCA_1_index(par("c1Index"));
         caReply->setCA_2_index(caIndex);
         send(caReply,"ca1ToBs$o",bs_sendIndex);
       }
       else if(isdeny(srcIndex))
       {
         ev<<"CA1"<<" get askCaMsg and denying bs["<<srcIndex<<"]";
         delete msg;
         caReply=new replyRenewMessage("caReply");
         caReply->setBs_src_index(bs_sendIndex);
         caReply->setTrust(false);  //say trust to lower bs
         caReply->setBs_search_index(srcIndex);
         caReply->setCA_1_index(par("c1Index"));
         caReply->setCA_2_index(caIndex);
         send(caReply,"ca1ToBs$o",bs_sendIndex);
       }
       else
       {
         delete msg;
         askCaMsg=new askRenewMessage("askCaMsg");
         askCaMsg->setBs_src_index(bs_sendIndex);
         askCaMsg->setBs_search_index(srcIndex); //node which to verify
         askCaMsg->setCA_1_index(par("c1Index"));  //upper belonged CA
         askCaMsg->setCA_2_index(caIndex);
         send(askCaMsg,"ca1ToCa2$o",caIndex);
       }
    }
    else if(strcmp(msg->getName(),"caReply")==0)
    {
       caReply=check_and_cast<replyRenewMessage*>(msg);
       bool choice= caReply->getTrust();
       if(choice==false)  //untrusted node
       {
         denyBsArr[curDenyNum]=caReply->getBs_search_index();
         curDenyNum++;
       }
       else if(choice==true)
       {
         trustBsArr[curTrustNum]=caReply->getBs_search_index();
         curTrustNum++;
       }

    }
    else
        delete msg;

}

void CA_1::gotoRegiste()
{
    setState(REGI);
    updateDisplay();
//    scheduleAt(simTime()+5*uniform(0,par("infoInterval")),selfSendData);
}
void CA_1::gotoUnregi()
{
    setState(UNREGI);
    updateDisplay();
    scheduleAt(simTime()+uniform(0,par("unregiTime")),selfRegiste);
}
void CA_1::setState(int state)
{
    if (state == OFF || state == UNREGI || state == REGI) {
        this->state = state;
    }
}
void CA_1::updateDisplay()
{
    cDisplayString &ds = getDisplayString();

    // Set color according to state
    switch (state) {
        case OFF:
            ds.setTagArg("i", 1, "black");
            break;
        case UNREGI:
            ds.setTagArg("i", 1, "grey");
            break;
        case REGI:
            ds.setTagArg("i", 1, "green");
            break;
    }
}

bool CA_1::istrust(int src)
{
   bool result=false;
   bool isfound=false;
   for(int i=0;i<curTrustNum;i++)
   {
       ev <<"[" <<trustBsArr[i] <<"]";
      if(trustBsArr[i]==src)
      isfound=true;     //found in array
   }
   if(isfound)
   {
      if(sigVerify())  //signature certi verify
        result=true;
      else
        result=false;
   }

   return result;
}

bool CA_1::isdeny(int src)
{
   for(int i=0;i<curDenyNum;i++)
   {
      if(denyBsArr[i]==src)
        return true;
   }
   return false;
}
bool CA_1::sigVerify()  //鏀惧叆RSA鍔犲瘑娴佺▼
{
    return true;
}
