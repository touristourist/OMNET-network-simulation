
package sensorBs;

//
// CA_3
//
simple CA_3 extends Entity   //level 1 CA
{
    parameters:
        int c3Index;
        @class(CA_3);
        @display("i=device/mainframe");
        double infoInterval = default(30);
	 	double offTime = default(120); 
        double unregiTime = default(30); 

    gates:
        inout ca3ToBs[];//connection from ca to basestation
        inout ca3ToCa2[];
}
