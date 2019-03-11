
#ifndef __MULTITARGETTRACKING_BASESTATION_H_
#define __MULTITARGETTRACKING_BASESTATION_H_

#include <omnetpp.h>
#include "entity.h"
#include "sensedsignal_m.h"
#include "selfDataStruct.h"
#include <string>

#define OFF 1  //δ����
#define UNREGI 2//δ��CA1��֤
#define REJ 4  //���ܱ���֤״̬
#define REGI 3  //�ѱ�CA1��֤

#define maxTrustBs 50
#define maxDenyBs 50
#define maxConnectSensor 200
int bscount=0;
/**
 * Base Station
 */
class BaseStation : public Entity
{
  private:
    SensorMessage *activeMsg;//get activeMsg from sensor
    SensorMessage *sensorMsg;
    SensorMessage *requestSensor;//����Ϣ
    int nowRequestIndex;//����Ҫ�����sensor��sensorIndexArr�����е��±�
    int connectSensorNum;
    int sensorIndexArr[maxConnectSensor]; //��������ӵ�sensor�±�
    int registablesSensor[10];//����Ǽǵ�sensor�±�
    int regSenNum;
    //////////////////////////////////////////////////////////////////
    int state;
    int caIndex;
    std::string rootsig;
    int curTrustNum;
    int trustBsArr[maxTrustBs];
    int curDenyNum;
    int denyBsArr[maxDenyBs];
    signatureCerti sigCerti;
    encryptionCerti encCerti;

    cMessage* selfstartMsg; //OFF -> UNREGI
    cMessage* selfRegiste;  //UNREGI��ת��REGI
    cMessage* selfSendData;
    certiMessage* certiRequest;  //ask for certi
    certiMessage* certiReply;  //get certireply from CA
    generalMessage* bsMsg;  //msg among bs
    askRenewMessage* askCaMsg; //ask for upper CA
    replyRenewMessage* caReply; //reply for lower CA��

   /////////////////////////////
    certiMessage* certiJudge;
///////////////////////////////////
    std::string uuid;
    std::string upper_uuid;
    std::string sign_public;
    std::string sign_private;

    std::string ency_public;
    std::string ency_private;

    int upper_index;


  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
  public:
    BaseStation();
    ~BaseStation();
    void gotoUnregi();
    virtual void updateDisplay();
    void setState(int state);
    void gotoRegiste();
    void sendData();
    bool istrust(int);
    bool isdeny(int);
    generalMessage* msgProcess(generalMessage * );
    bool sigVerify();
};

#endif
