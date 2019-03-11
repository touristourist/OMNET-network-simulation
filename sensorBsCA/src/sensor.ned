
package sensorBs;

//
// Wireless Sensor
//
simple Sensor extends Entity
{
    parameters:
        int sIndex;
        //int x=default(0);
        //int y=default(0);
        //int x;
//        string uuid;
//        int belongBsIndex;//属于的bs下标
		string infoFile = default("../simulations/sensorInfo.txt");

        double offTime = default(120); // Max sleep time
        double idleTime = default(30); // Idle time before sensor goes to sleep
//        double senseInterval = default(1); // Time between sensing frame
        @class(Sensor);
        @display("i=misc/node2;is=vs");

    gates:
        inout sensorToBs[]; // Connect to bs
        
}
