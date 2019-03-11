
#include "basestation.h"

#include<cstring>
#include<sstream>
#include<string>

#include <iostream>
#include <fstream>
Define_Module(BaseStation);

BaseStation::BaseStation()
{
    activeMsg= new SensorMessage("activeMsg");
    sensorMsg= new SensorMessage("sensorMsg");
    requestSensor=new SensorMessage("requestSensor");
    nowRequestIndex=0;
    connectSensorNum=0;
    for(int i=0;i<maxConnectSensor;i++)
        sensorIndexArr[i]=-1;
    //////////////////////////////////////////////////////
    curTrustNum=0;
    for(int i=0;i<maxTrustBs;i++)
        trustBsArr[i]=-1;
    state=OFF;
    curDenyNum=0;
    selfstartMsg=new cMessage("selfstartMsg");
    selfRegiste=new cMessage("selfRegiste");
    certiRequest=new certiMessage("certiRequest");
    bsMsg =new generalMessage("bsMsg");
    askCaMsg=new askRenewMessage("askCaMsg");

}

BaseStation::~BaseStation()
{

}

void BaseStation::initialize()
{
    std::ifstream in1("../simulations/bsRegiste.txt");
    bscount++;
    char s1[200]={};
    for(int i=0;i<bscount;i++){
        in1.getline(s1,sizeof(s1));
    }
    std::stringstream word1(s1);
    //word >> registablesSensor[0];
    //ev << registablesSensor[0] << " ";
    //regSenNum++;

    regSenNum = 0;
    while(word1 >> registablesSensor[regSenNum]){
        //ev << registablesSensor[regSenNum] << " ";
        regSenNum++;
    }
    ev << "abss";


    std::ifstream in("../simulations/BS_Info.txt");

    int xtemp;
    int ytemp;
    char s[500]={};
    for(int i=0;i<bscount;i++){
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
    word >> ency_public;
    word >> ency_private;

    setX(xtemp);
    setY(ytemp);
    cDisplayString &dspy = getDisplayString();

    dspy.setTagArg("p",0,x);
    dspy.setTagArg("p",1,y);


    caIndex=upper_index;
//    cModule *wsn = simulation.getModuleByPath("Wsn");
//    double w = wsn->par("width");
//    double h = wsn->par("height");
//    int b_i=par("bIndex");
//    switch(b_i)
//    {
//    case 0:
//        par("x")=intuniform(0,w/2);
//        par("y")=intuniform(0,h/2);
//        break;
//    case 1:
//        par("x")=intuniform(w/2,w);
//        par("y")=intuniform(0,h/2);
//        break;
//    case 2:
//        par("x")=intuniform(0,w/2);
//        par("y")=intuniform(h/2,h);
//        break;
//    case 3:
//        par("x")=intuniform(w/2,w);
//        par("y")=intuniform(h/2,h);
//        break;
//    }
    //////////////////////////////////////////////////////////

    scheduleAt(uniform(0,par("offTime")),selfstartMsg);

}

void BaseStation::handleMessage(cMessage *msg)
{
//   if(state==UNREGI)
//   {
//       if((strcmp(msg->getName(), "rejectMsg") != 0)&&(strcmp(msg->getName(), "selfRegiste") != 0))
//           scheduleAt(simTime()+uniform(0,par("unregiTime")),selfRegiste);
//       else
//       {
//           state=REJ;
//           delete msg;
//       }
//   }
   ///////////////////////////////////////////////////
   if (strcmp(msg->getName(), "activeMsg") == 0)
   {
       activeMsg= check_and_cast<SensorMessage*>(msg);
       int regAble=false;
       int senIndex=activeMsg->getSensor_index();
       for(int i=0;i<regSenNum;i++)
           if (senIndex==registablesSensor[i])
           {
               regAble=true;
               break;
           }
       if(regAble==true)
       {
                  int s_i=activeMsg->getSensor_index();
                  activeMsg->setAction("activate");    //鍥炲sensor activeMsg
                  send(activeMsg,"bsToSensor$o",s_i);

                  sensorIndexArr[connectSensorNum]=s_i;//鐧昏璇ensor涓嬫爣
                  connectSensorNum++;//sensor鏁伴噺鍔犱竴
                  //connectSensorNum浣滀负涓嬫爣鏃讹紝琛ㄧず褰撳墠闇�濉叆鐨剆ensor涓嬫爣
                  //connectSensorNum浣滀负鏁扮洰锛岃〃绀哄綋鍓嶅凡杩炴帴sensor鏁伴噺

                  if(connectSensorNum==1)//鍙戦�绗竴涓猺equestSensor娑堟伅
                  {
                      requestSensor->setSensor_index(s_i);
                      double interTime=uniform(10,par("infoInterval"));
                      scheduleAt(simTime()+interTime,requestSensor);
                  }
       }
       else //涓嶈兘registe
           delete msg;
   }
   else if(strcmp(msg->getName(), "requestSensor")==0)
   {    //鏀跺埌鑷秷鎭紝瑕佸悜sensor鍙戞秷鎭姹俿ensorMsg
       requestSensor= check_and_cast<SensorMessage*>(msg);

       sensorMsg=new SensorMessage("sensorMsg");
       int s_index=sensorIndexArr[nowRequestIndex];
       sensorMsg->setSensor_index(s_index);
       sensorMsg->setSensor_xPos(-1);
       sensorMsg->setSensor_yPos(-1);
       sensorMsg->setBs_index(par("bIndex"));
       sensorMsg->setSensor_signal(-1);
       sensorMsg->setAction("getInfo");

       send(sensorMsg,"bsToSensor$o",s_index);


       nowRequestIndex=(nowRequestIndex+1)%connectSensorNum;
       //requestSensor->setSensor_index(s_index);
       double interTime=uniform(10, par("infoInterval"));
       scheduleAt(simTime()+interTime,requestSensor);

       //delete msg;
   }
   else if(strcmp(msg->getName(), "sensorMsg") == 0)//鏀跺埌sensor鍙戞潵鐨刬nfo
   {
       sensorMsg=check_and_cast<SensorMessage*>(msg);
       EV << "get Info from sensor["<<sensorMsg->getSensor_index()<<"]";
       delete msg;
   }
   ///////////////////////////////////////////////////////////////涓嶤A,BS浜や簰
   else if(strcmp(msg->getName(), "selfstartMsg") == 0)
   {
       if(state==OFF)
       {
           gotoUnregi();
           delete msg;
       }
   }
   else if(strcmp(msg->getName(), "selfRegiste") == 0) //产生请求证书事件
   {
       if(state==UNREGI)
       {
           certiRequest=new certiMessage("certiRequest");
           certiRequest->setSrc_index(par("bIndex"));
           send(certiRequest,"bsToCa1$o",caIndex);
           //selfRegiste=new cMessage("selfRegiste");
           delete msg;
           //scheduleAt(simTime()+uniform(1000,100*par("unregiTime")),selfRegiste);

       }
       else
        delete msg;
   }
   else if(strcmp(msg->getName(), "rejectMsg") == 0)  //get reject from upper
   {
       state=REJ;
       ev << "reject";
       delete msg;
   }

   else if(strcmp(msg->getName(), "certiReply") == 0)  //得到返回的证书
   {
         certiReply=check_and_cast<certiMessage*>(msg);
//       sigCerti.src_id=certiReply->getSig_srcid();  //set self sigCerti
//       sigCerti.src_comkey=certiReply->getSig_srccomkey();
//       sigCerti.CA_id=certiReply->getSig_CAid();
//       sigCerti.CA_sig=certiReply->getSig_CAsig();
       gotoRegiste();
       delete msg;
   }
   else if(strcmp(msg->getName(), "selfSendData") == 0)
   {
         sendData();
//       delete msg;
   }

   else if(strcmp(msg->getName(), "bsMsg") == 0)
   {
       bsMsg=check_and_cast<generalMessage*>(msg);
       int srcIndex=bsMsg->getSrc_index();
       int ord=par("bIndex");
       if(istrust(srcIndex))  //鍙戦�bsMSg鐨勬簮鑺傜偣鍜岃嚜宸卞浜庡悓涓�A涓紝涓�璁よ瘉閫氳繃.鎴栬�涔嬪墠宸茬粡楠岃瘉杩囧彲淇�       {
       {
// 不能直接输出par(),ev<<"bs["<<(int)par("bIndex"))<<"]"<<" GET bs msg from: bs["<<srcIndex<<"]";
           ev<<"bs["<<ord<<"] GET bs msg from: bs["<<srcIndex<<"]";
           delete msg;
       }
       else if(isdeny(srcIndex))  //if sender is denied
       {
//        ev<<"bs["<<par("bIndex")<<"]"<<" DENY bs msg from: bs["<<srcIndex<<"]";
          ev<<"bs["<<ord<<"] DENY bs msg from: bs["<<srcIndex<<"]";
          delete msg;
       }
       else  //can not judge sender
       {
         delete msg;
         askCaMsg=new askRenewMessage("askCaMsg");
         askCaMsg->setBs_src_index(par("bIndex"));
         askCaMsg->setBs_search_index(srcIndex); //node which to verify
         askCaMsg->setCA_1_index(caIndex);  //upper belonged CA
         askCaMsg->setCA_2_index(-1);
         send(askCaMsg,"bsToCa1$o",caIndex);
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

      delete msg;
   }
   else
       delete msg;



}
void BaseStation::gotoRegiste()
{
    setState(REGI);
    updateDisplay();
    selfSendData=new cMessage("selfSendData");
    ev << "bs goto registe";
    scheduleAt(simTime()+5*uniform(0,par("infoInterval")),selfSendData);
}
void BaseStation::sendData()
{
    cModule *wsn = simulation.getModuleByPath("Wsn");
    int maxIndex=wsn->par("numBase");
    int rindex=intuniform(0,maxIndex-1);
    generalMessage* tempMsg =new generalMessage("bsMsg");
    int ord=par("bIndex");
    tempMsg->setBs_uuID("");
//    tempMsg->setBs_x();
//    tempMsg->setBs_y();
    tempMsg->setSrc_index(ord);
//    tempMsg->setSignal();
//    tempMsg->setInfo();
//    tempMsg->setSend_time();
//
//    tempMsg->setSig_srcid();
//    tempMsg->setSig_srccomkey();
//    tempMsg->setSig_CAid();
//    tempMsg->setSig_CAsig();
//    tempMsg->setSig_srcIndex();
//    tempMsg->setSig_type();
//    tempMsg->setEnc_srcid();
//    tempMsg->setEnc_srccomkey();
//    tempMsg->setEnc_CAid();
//    tempMsg->setEnc_CAsig();

    bsMsg=msgProcess(tempMsg);//瀵瑰彂閫佺殑鏁版嵁杩涜鍔犲瘑
    send(bsMsg,"bsout",rindex);

    if(selfSendData->isScheduled())
        cancelEvent(selfSendData);
    scheduleAt(simTime()+ par("infoInterval") ,selfSendData);
}
void BaseStation::gotoUnregi()
{
    setState(UNREGI);
    ev << "bs goto unregister";
    updateDisplay();
    scheduleAt(simTime()+uniform(0,par("unregiTime")),selfRegiste);
}
void BaseStation::setState(int state)
{
    if (state == OFF || state == UNREGI || state == REGI) {
        this->state = state;
    }
}
void BaseStation::updateDisplay()
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
///////////////////////////////////////////////////////////////////////
bool BaseStation::istrust(int src)   //判断给自己发消息的bs是否信任
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

bool BaseStation::isdeny(int src)   //judge whether to deny
{

    for(int i=0;i<curDenyNum;i++)
    {
      if(denyBsArr[i]==src)
        return true;
    }
    return false;
}

bool BaseStation::sigVerify()   //verify sig certi
{
  return true;
}

generalMessage* BaseStation::msgProcess(generalMessage * msg)
{
    return msg;
}
