
#include "sensor.h"

#include<cstring>
#include<sstream>
#include<string>

#include "entity.h"
#include "sensedsignal_m.h"
#include <iostream>
#include <fstream>

Define_Module(Sensor);

Sensor::Sensor()//���캯����ֻ�ܶ�Sensor.h�ж���ı������в��������ܶ�ned��������
{
    state = STATE_OFF;

    // Create self messages
    // 'Go to idle' timer
    idleMsg = new cMessage("idleMsg");
    // Wake-up timer
    selfactiveMsg = new cMessage("selfactiveMsg");

    activeMsg= new SensorMessage("activeMsg");
    // Sensing timer
    sensorMsg = new SensorMessage("sensorMsg");
}

Sensor::~Sensor()
{
    cancelAndDelete(idleMsg);
    cancelAndDelete(selfactiveMsg);
    cancelAndDelete(sensorMsg);
}

//int Sensor::divSensor()
//{
//    cModule *wsnNet = simulation.getModuleByPath("Wsn");
//    int wid=wsnNet->par("width");
//    int heg=wsnNet->par("height");
//    int sx=par("x");
//    int sy=par("y");
//    if(0<=sx&&sx<(wid/2))
//    {
//        if(0<=sy&&sy<(heg/2))
//            return 0;//��һ����bsindex=0
//        else if((heg/2)<=sy&&sy<=heg)
//            return 2;//����bsindex=2
//    }
//    else if((wid/2)<=sx&&sx<=wid)
//    {
//        if(0<=sy&&sy<(heg/2))
//            return 1;//�ڶ�bsindex=1
//        else if((heg/2)<=sy&&sy<=heg)
//            return 3;//bsindex=3
//    }
//    return 0;
//}


void Sensor::initialize()
{
    int xtemp;
    int ytemp;

    std::ifstream in("../simulations/sensorInfo.txt");
    count++;
    char s[200]={};
    for(int i=0;i<count;i++){
        in.getline(s,sizeof(s));
    }
    std::stringstream word(s);
    word >> sensoruuid;
    word >> belongBsIndex;
    word >> bsuuid;
    word >> xtemp;
    word >> ytemp;
    word >> type;

    setX(xtemp);
    setY(ytemp);
    // ����ֱ�Ӹ���entity��x��y

    //type = intuniform(1,4);
    cDisplayString &dspy = getDisplayString();

    dspy.setTagArg("p",0,x);
    dspy.setTagArg("p",1,y);

    switch(type)
    {
    case Tsensor:
        dspy.setTagArg("i", 0, "misc/node");
        break;
    case Psensor:
        dspy.setTagArg("i", 0, "misc/node2");
        break;
    case Lsensor:
        dspy.setTagArg("i", 0, "misc/square");
        break;
    case Isensor:
        dspy.setTagArg("i", 0, "misc/square2");
        break;
    case Nsensor:
        break;
    case Ksensor:
        break;
    }



    // Initial state is off
    setState(STATE_OFF);
    //belongBsIndex = 2;//ȷ��sensor���ڵ�bsinsex
    // randomly start to registe to bs
    scheduleAt(uniform(0, par("offTime")), idleMsg);   //����Ϣ��idlemessage
}

void Sensor::handleMessage(cMessage *msg)
{

    if (msg == idleMsg)
    {
        if(state==STATE_OFF)
        {
            gotoidle();
            //state=STATE_IDLE; //��off->idle
            delete msg;
        }
        else
        {
            EV << "idleMsg get error (need to be canceled)";
            cancelAndDelete(msg);
        }
//         gotoidle();
    }
    else if (msg == selfactiveMsg)
    {
        if(state==STATE_IDLE)
        {//�ȴ����active״̬
            sendToRegiste();
            delete msg;
        }
        else
        {
            EV << "selfactiveMsg get error (need to be canceled)";
            cancelAndDelete(msg);
        }

    }
    else if(strcmp(msg->getName(), "activeMsg") == 0)//���յ�bs��activate��Ϣ
    {
        if(state==STATE_IDLE)
        {   //���active״̬
            //    state=STATE_ACTIVE;
            activate();
            delete msg;
        }
        else
        {
            EV << "activeMsg get error (need to be canceled)";
            cancelAndDelete(msg);
        }
    }
    else if (strcmp(msg->getName(), "sensorMsg") == 0)
    {
        sendInfoToBs();
        delete msg;
    }

}

void Sensor::sendToRegiste()
{
    activeMsg=new SensorMessage("activeMsg");

    activeMsg->setSensor_index(par("sIndex"));
    activeMsg->setSensor_xPos(par("x"));
    activeMsg->setSensor_yPos(par("y"));
    activeMsg->setBs_index(belongBsIndex);

    activeMsg->setAction("Registe");

    send(activeMsg,"sensorToBs$o",belongBsIndex);
    //activeMsg=NULL;
}

void Sensor::sendInfoToBs()
{
    sensorMsg=new SensorMessage("sensorMsg");

    sensorMsg->setSensor_index(par("sIndex"));
    sensorMsg->setSensor_xPos(par("x"));
    sensorMsg->setSensor_yPos(par("y"));
    sensorMsg->setBs_index(belongBsIndex);
    double info=uniform(1,100);
    sensorMsg->setSensor_signal(info);
    sensorMsg->setAction("sendInfo");

    send(sensorMsg,"sensorToBs$o",belongBsIndex);

}

/*
 * Update display of sensor in simulation
 */
void Sensor::updateDisplay()
{
    cDisplayString &ds = getDisplayString();

    // Update displayed position according to object's coordination (x,y)
    //ds.setTagArg("p", 0, x);
    //ds.setTagArg("p", 1, y);

    // Set color according to state
    switch (state) {
        case STATE_OFF:
            ds.setTagArg("i", 1, "black");
            break;
        case STATE_IDLE:
            ds.setTagArg("i", 1, "grey");
            break;
        case STATE_ACTIVE:
            ds.setTagArg("i", 1, "green");
            break;
    }
}

/*
 * Get current state of the sensor
 */
int Sensor::getState()
{
    return state;
}

/*
 * Set working state of the sensor
 */
void Sensor::setState(int state)
{
    if (state == STATE_OFF || state == STATE_IDLE || state == STATE_ACTIVE) {
        this->state = state;
    }
}

/*
 * Set state to active and plan a 'go-to-idle' timer.
 * This function is called only when the sensor wakes up itself, not by a call from other sensors.
 */
void Sensor::activate()
{
    setState(STATE_ACTIVE);
    updateDisplay();

    //scheduleAt(simTime() + par("idleTime"), idleMsg);  //idle�����idle

    // Start sensing immediately
    //scheduleAt(simTime(), sensorMsg);
}

/*
 * Set state to idle and plan a wake up timer
 */
void Sensor::gotoidle()
{
    setState(STATE_IDLE);
    updateDisplay();

    // Plan for wake up after idleTime
    // If a working event occurs, wake up immediately and cancel this timer
    scheduleAt(simTime() + par("idleTime"), selfactiveMsg);//��idle״̬׼��ע��registe
}


