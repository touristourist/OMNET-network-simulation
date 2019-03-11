
#include "CA_3.h"

#include<cstring>
#include<sstream>
#include<string>

#include <iostream>
#include <fstream>

Define_Module(CA_3);

CA_3::CA_3()
{
    state=OFF;
    curDenyNum=0;

    for(int i=0;i<maxTrustBs;i++)
        trustBsArr[i]=-1;

    selfstartMsg=new cMessage("selfstartMsg");
//    selfRegiste=new cMessage("selfRegiste");
    certiRequest=new certiMessage("certiRequest");
//    CertiReply=new certiMessage("CertiReply");
    rejectMsg=new cMessage("rejectMsg");
//    askCaMsg=new askRenewMessage("askCaMsg"); //get from lower CA
    caReply=new replyRenewMessage("caReply");


    curTrustNum=0;
    //证书还要初始化
}

CA_3::~CA_3()
{

}

void CA_3::initialize()
{
    state=REGI;   //root结点CA一启动就开启状态
    std::ifstream in("../simulations/CA_3_Info.txt");
    CA3_count++;

    int xtemp;
    int ytemp;
    char s[500]={};
    for(int i=0;i<CA3_count;i++){
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

    std::ifstream in1("../simulations/CA_3_Trust_Info.txt");
    int index;
    curTrustNum = 0;
    while(in1.getline(s,sizeof(s))){
        std::stringstream word(s);
        word >> index;
        //ev << 'index:' << index << ',';
        if(index == CA3_count - 1 ){
            word >> trustBsArr[curTrustNum];
            ev << trustBsArr[curTrustNum] << " ";
            curTrustNum++;
        }
    }
    ev << std::endl;


    scheduleAt(uniform(0,par("offTime")),selfstartMsg);



}

void CA_3::handleMessage(cMessage *msg)
{
    if(strcmp(msg->getName(), "certiRequest")==0)  //收到bs的证书请求
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
            send(certiReply,"ca3ToCa2$o",deIndex);
        }
        else //否则拒绝
        {
            rejectMsg=new cMessage("rejectMsg");
            send(rejectMsg,"ca3ToCa2$o",deIndex);
        }

        delete msg;
    }

    else if(strcmp(msg->getName(),"askCaMsg")==0) //asked by lower bs
    {
       askCaMsg=check_and_cast<askRenewMessage*>(msg);
       int srcIndex=askCaMsg->getBs_search_index(); //the judged node
       int bs_sendIndex=askCaMsg->getBs_src_index();  //the answerd node
       int ca_sendIndex=askCaMsg->getCA_2_index();
       int ca1tempIndex=askCaMsg->getCA_1_index();
       if(istrust(srcIndex))
       {
         ev<<"CA3"<<" get askCaMsg and verifying bs["<<srcIndex<<"]";
         delete msg;
         caReply=new replyRenewMessage("caReply");
         caReply->setBs_src_index(bs_sendIndex);
         caReply->setTrust(true);  //say trust to lower bs
         caReply->setBs_search_index(srcIndex);
         caReply->setCA_1_index(ca1tempIndex);
         caReply->setCA_2_index(ca_sendIndex);
         send(caReply,"ca3ToCa2$o",ca_sendIndex);
       }
       else if(isdeny(srcIndex))
       {
         ev<<"CA3"<<" get askCaMsg and denying bs["<<srcIndex<<"]";
         delete msg;
         caReply=new replyRenewMessage("caReply");
         caReply->setBs_src_index(bs_sendIndex);
         caReply->setTrust(false);  //send trust to lower bs
         caReply->setBs_search_index(srcIndex);
         caReply->setCA_1_index(ca1tempIndex);
         caReply->setCA_2_index(ca_sendIndex);
         send(caReply,"ca3ToCa2$o",ca_sendIndex);
       }
       else
       {
         delete msg;
         int denyBs=askCaMsg->getBs_search_index();
         denyBsArr[curDenyNum]=denyBs;
         curDenyNum++;
       }
    }

    else
        delete msg;
}

void CA_3::updateDisplay()
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

bool CA_3::istrust(int src)
{
   bool result=false;
   bool isfound=false;
   for(int i=0;i<curTrustNum;i++)
   {
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

bool CA_3::isdeny(int src)
{
   for(int i=0;i<curDenyNum;i++)
   {
      if(denyBsArr[i]==src)
        return true;
   }
   return false;
}

bool CA_3::sigVerify()
{
    return true;
}
