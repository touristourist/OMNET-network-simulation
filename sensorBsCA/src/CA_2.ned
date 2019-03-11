
package sensorBs;

//
// CA_2
//
simple CA_2 extends Entity   //level 1 CA
{
    parameters:
        int c2Index;
        @class(CA_2);
        @display("i=device/lan-bus");
        double infoInterval = default(30);
	 	double offTime = default(120); 
        double unregiTime = default(30); 

    gates:
        inout ca2ToBs[];//connection from ca to basestation
        inout ca2ToCa3[];
        inout ca2ToCa1[];
}
