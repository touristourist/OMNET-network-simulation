
message SensorMessage    //sensor发送给bs的消息
{
    string sensor_uuID;  //sensor的ID
    int sensor_index;   //该sensor标号
    int sensor_xPos;    //x坐标
    int sensor_yPos;    //y坐标
    string bs_uuID;     //目的bs的ID
    int bs_index;       //目的bs的标号
    
    string action;         //表示sensor发送的该条信息的目的
    double sensor_signal;   //sensor发送的信息
    double send_time;       //发送时间
}

message generalMessage  //bs之间发送的消息格式定义
{
    //data area 要传输的各项信息
    string bs_uuID;   //ID
    int bs_x;        //x坐标
    int bs_y;        //y坐标
    int src_index;   //标号
    double signal;    //传输的浮点数据
    string info;      //传输的字符串
    double send_time;   //发送时间
    
    //data signature  对于上述各项信息的签名
    string data_sig;
    
    //signature certificate  签名证书
    string sig_srcid;      //发送节点的ID
    string sig_srccomkey;  //签名公钥
    string sig_CAid;       //认证CA的ID
    string sig_CAsig;      //认证CA的签名
    int sig_srcIndex;      //认证CA的标号
    int sig_type;
    
    //encryption certificate 加密证书
    string enc_srcid;       //节点ID
    string enc_srccomkey;   //加密公钥
    string enc_CAid;        //认证CA的ID
    string enc_CAsig;       //认证CA的签名
}    

message certiMessage     //只包含了签名证书的消息
{
    string sig_srcid;
    string sig_srccomkey;  //签名公钥
    string sig_CAid;
    string sig_CAsig;
    //
    int src_index;  //发出该消息的结点
    int sig_srcIndex; //签名结点
    int sig_type; 
} 

message askRenewMessage//源端bs向CA询问是否可以与目的bs通信
{
    int bs_src_index;     //源端发出请求的bs
    int bs_search_index;  //要查找的bs
    int CA_1_index;       //途经的CA1
    int CA_2_index;      //途经的CA2
}

message replyRenewMessage//上级CA回复给下级的结果
{
    int bs_src_index;     //最终要回复的bs
    int bs_search_index;  //要查找的bs
    bool trust;           //是否可以通信的结果
    int CA_1_index;       //途经的CA_1
    int CA_2_index; 	  //途经的CA_2
}