
#ifndef __MULTITARGETTRACKING_BASESTATION_H_
#define __MULTITARGETTRACKING_BASESTATION_H_

#include <omnetpp.h>
#include "entity.h"
#include "sensedsignal_m.h"
#include "selfDataStruct.h"

#define OFF 1  //δ����
#define UNREGI 2//δ�����߼����CA��֤
#define REGI 3  //�ѱ����߼���CA��֤
#define REJ 4  //���ܱ���֤״̬


//#define maxConnectSensor 200
//int bscount=0;
/**
 * CA2
 */
#define maxTrustBs 50
#define maxDenyBs 50

int CA2_count=0;

class CA_2 : public Entity
{
  private:

    int state;
    int caIndex;
    std::string rootsig;  //�����
    int curTrustNum;
    int curDenyNum;
    int trustBsArr[maxTrustBs];
    int denyBsArr[maxDenyBs];
    signatureCerti sigCerti;  //���ε�ca֤��
    encryptionCerti encCerti;

    cMessage* selfstartMsg; //OFF -> UNREGI
    cMessage* selfRegiste; //UNREGI ��ҪתΪ REGI
    certiMessage* certiRequest;  //ask for certi
    certiMessage* certiReply;   //reply certi request from others
    cMessage* rejectMsg;  //�ܾ��Է���֤����
    askRenewMessage* askCaMsg; //�����ϲ�ca
    replyRenewMessage* caReply; //�ϲ�ca�ظ�


    std::string uuid;
    std::string upper_uuid;
    std::string sign_public;
    std::string sign_private;

    int upper_index;

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
  public:
    CA_2();
    ~CA_2();
    void gotoUnregi();
    virtual void updateDisplay();
    void setState(int state);
    void gotoRegiste();
    void sendData();
    bool istrust(int );
    bool isdeny(int );
    generalMessage* msgProcess(generalMessage *);
    bool sigVerify();

};

#endif
