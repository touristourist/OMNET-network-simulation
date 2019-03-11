
#include "CA_2.h"

#include<cstring>
#include<sstream>
#include<string>

#include <iostream>
#include <fstream>

Define_Module(CA_2);

CA_2::CA_2()
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

CA_2::~CA_2()
{

}

void CA_2::initialize()
{
    std::ifstream in("../simulations/CA_2_Info.txt");
    CA2_count++;

    int xtemp;
    int ytemp;
    char s[500]={};
    for(int i=0;i<CA2_count;i++){
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



    std::ifstream in1("../simulations/CA_2_Trust_Info.txt");
    int index;
    curTrustNum = 0;
    while(in1.getline(s,sizeof(s))){
        std::stringstream word(s);
        word >> index;
        //ev << 'index:' << index << ',';
        if(index == CA2_count - 1){
            word >> trustBsArr[curTrustNum];
            ev << trustBsArr[curTrustNum] << " ";
            curTrustNum++;
        }
    }
    ev << std::endl;

}

void CA_2::handleMessage(cMessage *msg)
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
         certiRequest->setSrc_index(par("c2Index")); //源端
         send(certiRequest,"ca2ToCa3$o",caIndex);
         delete msg;
       }
       else
         delete msg;

    }
    else if(strcmp(msg->getName(), "certiRequest")==0)  //收到bs的证书请求
    {
        certiRequest=check_and_cast<certiMessage*>(msg);
        int deIndex=certiRequest->getSrc_index();
        if(istrust(deIndex))  //是能认证的bs
        {
            certiReply=new certiMessage("certiReply");
            certiReply->setSig_srcid((sigCerti.src_id).c_str());
            certiReply->setSig_srccomkey((sigCerti.src_comkey).c_str());
            certiReply->setSig_CAid((sigCerti.CA_id).c_str());
            certiReply->setSig_CAsig((sigCerti.CA_sig).c_str());
            send(certiReply,"ca2ToCa1$o",deIndex);
        }
        else //否则拒绝
        {
            rejectMsg=new cMessage("rejectMsg");
            send(rejectMsg,"ca2ToCa1$o",deIndex);
        }

        delete msg;
    }
    else if(strcmp(msg->getName(), "certiReply") == 0)//收到ca2回复,have been verified by CA2
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
       int ca_sendIndex=askCaMsg->getCA_1_index();
       if(istrust(srcIndex))
       {
         ev<<"CA2"<<" get askCaMsg and verifying bs["<<srcIndex<<"]";
         delete msg;
         caReply=new replyRenewMessage("caReply");
         caReply->setBs_src_index(bs_sendIndex);
         caReply->setTrust(true);  //say trust to lower bs
         caReply->setBs_search_index(srcIndex);
         caReply->setCA_1_index(ca_sendIndex);
         caReply->setCA_2_index(par("c2Index"));
         send(caReply,"ca2ToCa1$o",ca_sendIndex);
       }
       else if(isdeny(srcIndex))
       {
         ev<<"CA1"<<" get askCaMsg and denying bs["<<srcIndex<<"]";
         delete msg;
         caReply=new replyRenewMessage("caReply");
         caReply->setBs_src_index(bs_sendIndex);
         caReply->setTrust(false);  //say trust to lower bs
         caReply->setBs_search_index(srcIndex);
         caReply->setCA_1_index(ca_sendIndex);
         caReply->setCA_2_index(par("c2Index"));
         send(caReply,"ca2ToCa1$o",ca_sendIndex);
       }
       else
       {
         delete msg;
         askCaMsg=new askRenewMessage("askCaMsg");
         askCaMsg->setBs_src_index(bs_sendIndex);
         askCaMsg->setBs_search_index(srcIndex); //node which to verify
         askCaMsg->setCA_1_index(ca_sendIndex);  //upper belonged CA
         askCaMsg->setCA_2_index(par("c2Index"));
         send(askCaMsg,"ca2ToCa3$o",caIndex);
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

void CA_2::gotoRegiste()
{
    setState(REGI);
    updateDisplay();
//    scheduleAt(simTime()+5*uniform(0,par("infoInterval")),selfSendData);
}
void CA_2::gotoUnregi()
{
    setState(UNREGI);
    updateDisplay();
    scheduleAt(simTime()+uniform(0,par("unregiTime")),selfRegiste);
}
void CA_2::setState(int state)
{
    if (state == OFF || state == UNREGI || state == REGI) {
        this->state = state;
    }
}
void CA_2::updateDisplay()
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

bool CA_2::istrust(int src)
{
   bool result=false;
   bool isfound=false;
   for(int i=0;i<curTrustNum;i++)
   {
      if(trustBsArr[i]==src)
      isfound=true;     //found in array
   }
//   isfound=false;
   if(isfound)
   {
      if(sigVerify())  //signature certi verify
        result=true;
      else
        result=false;
   }

   return result;
}

bool CA_2::isdeny(int src)
{

   for(int i=0;i<curDenyNum;i++)
   {
      if(denyBsArr[i]==src)
        return true;
   }
   return false;
}

bool CA_2::sigVerify()
{
    return true;
}
