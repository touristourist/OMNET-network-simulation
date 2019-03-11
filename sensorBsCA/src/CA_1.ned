
package sensorBs;

//
// CA_1
//
simple CA_1 extends Entity   //level 1 CA
{
    parameters:
        int c1Index;
        @class(CA_1);
        @display("i=device/lan-ring");
	 	double infoInterval = default(30);
	 	double offTime = default(120); 
        double unregiTime = default(30); 
    gates:
        inout ca1ToBs[];//connection from ca to basestation
        inout ca1ToCa2[];
        
}
