
#ifndef __MULTITARGETTRACKING_SENSOR_H_
#define __MULTITARGETTRACKING_SENSOR_H_

#include <omnetpp.h>
#include "entity.h"
#include "sensedsignal_m.h"
#include <cstring>

// three sensor states
#define STATE_OFF 0 // not registe to basestation
#define STATE_IDLE 1 // not send message to basestation
#define STATE_ACTIVE 2 // Sensing and transmit data
//
#define Tsensor 1
#define Psensor 2
#define Lsensor 3
#define Isensor 4
#define Nsensor 5
#define Ksensor 6

int count=0;
/**
 * Wireless Sensor
 */
class Sensor : public Entity
{
    private:
        //string uuid;
        int belongBsIndex;//属于的bs下标
        int type;
        std::string sensoruuid;
        std::string bsuuid;

        int state; // Working state
        cMessage *idleMsg; // Self message for sensor goes from state_off to state_idle
        cMessage *selfactiveMsg; // Self message for sensor goes from state_idle to state_active

        SensorMessage *activeMsg;//send to bs to registe
        SensorMessage *sensorMsg; // message for transmit info to bs

        void activate();
        void gotoSleep();
        void startSense();
        void recvSenseData(SensorMessage *sig);

    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);

    public:
        Sensor();
        ~Sensor();
        int divSensor();
        void sendToRegiste();
        void sendInfoToBs();
        void gotoidle();
        virtual void updateDisplay();
        int getState();
        void setState(int state);
};

#endif
