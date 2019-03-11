
package sensorBs;

//
// Base Station
//
simple BaseStation extends Entity
{
    parameters:
        int bIndex;
        @class(BaseStation);
        @display("i=device/pocketpc");
        //        string sensoruuid;     //记录下属sensor的UUID
        double infoInterval = default(30);//向sensor从激活到第一次发出请求信息间隔
		//double nextInterval=default(120);//向同一sensor请求的周期
		double offTime = default(120); 
        double unregiTime = default(30); 
    gates:
        inout bsToSensor[];
        input bsin[];
        output bsout[];
        inout bsToCa1[];
        inout bsToCa2[];
        inout bsToCa3[];
}
