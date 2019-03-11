
package sensorBs;

network Wsn
{
    parameters:
        double width = default(640);
        double height = default(560);
        int numSensor;
        int numBase;
        int numCA1;
        int numCA2;
        int numCA3;
        int ssRows; // Number of sensor rows
        int ssCols; // Number of sensor columns
        // Note: First ssRows * ssCols sensors will be arranged, the rest is randomly distributed
        @display("bgb=640,560");  //background

    types:   //理想信道
        channel SenseChannel extends ned.IdealChannel
        {
            @display("ls=,0"); // Hide connection line
        }

    submodules:
        bs[numBase]: BaseStation {
            bIndex = index;
            //         	x = intuniform(0, width);    //传感器x,y坐标随机生成
            //            y = intuniform(0, height);
            @display("p=322,381");
            gates:
                bsToSensor[numSensor];
                bsin[numBase];
                bsout[numBase];
                bsToCa1[numCA1];
                bsToCa2[numCA2];
                bsToCa3[numCA3];
        }    //基站
        sensor[numSensor]: Sensor {
            sIndex = index; // sindex is also index in sensor vector
            @display("p=322,471");
            //x = intuniform(0, width);    //传感器x,y坐标随机生成
            //y = intuniform(0, height);
            //@display("p=$x, $y");
            gates:
                sensorToBs[numBase];   //每个传感器都与所有bs连接，下标表示bs序号
        }
        certiAuth1[numCA1]: CA_1 {
            c1Index = index;
            @display("p=221,278");
            gates:
                ca1ToBs[numBase];
                ca1ToCa2[numCA2];

        }
        certiAuth2[numCA2]: CA_2 {
            c2Index = index;

            @display("p=434,184");
            gates:
                ca2ToBs[numBase];
                ca2ToCa3[numCA3];
                ca2ToCa1[numCA1];

        }
        certiAuth3[numCA3]: CA_3 {
            c3Index = index;
            @display("p=287,64");
            gates:
                ca3ToBs[numBase];
                ca3ToCa2[numCA2];

        }

    connections:
        for i=0..(numBase - 1), for j=0..(numSensor - 1) {
            bs[i].bsToSensor[j] <--> SenseChannel <--> sensor[j].sensorToBs[i];
        }
        for i=0..(numBase-1), for j=0..(numBase-1) {
            bs[i].bsout[j] --> SenseChannel --> bs[j].bsin[i];
        }
        for i=0..(numBase - 1), for j=0..(numCA1 - 1) {
            bs[i].bsToCa1[j] <--> SenseChannel <--> certiAuth1[j].ca1ToBs[i];
        }
        for i=0..(numBase - 1), for j=0..(numCA2 - 1) {
            bs[i].bsToCa2[j] <--> SenseChannel <--> certiAuth2[j].ca2ToBs[i];
        }
        for i=0..(numBase - 1), for j=0..(numCA3 - 1) {
            bs[i].bsToCa3[j] <--> SenseChannel <--> certiAuth3[j].ca3ToBs[i];
        }
        for i=0..(numCA1 - 1), for j=0..(numCA2 - 1) {
            certiAuth1[i].ca1ToCa2[j] <--> SenseChannel <--> certiAuth2[j].ca2ToCa1[i];
        }
        for i=0..(numCA2 - 1), for j=0..(numCA3 - 1) {
            certiAuth2[i].ca2ToCa3[j] <--> SenseChannel <--> certiAuth3[j].ca3ToCa2[i];
        }
}
