
message SensorMessage    //sensor���͸�bs����Ϣ
{
    string sensor_uuID;  //sensor��ID
    int sensor_index;   //��sensor���
    int sensor_xPos;    //x����
    int sensor_yPos;    //y����
    string bs_uuID;     //Ŀ��bs��ID
    int bs_index;       //Ŀ��bs�ı��
    
    string action;         //��ʾsensor���͵ĸ�����Ϣ��Ŀ��
    double sensor_signal;   //sensor���͵���Ϣ
    double send_time;       //����ʱ��
}

message generalMessage  //bs֮�䷢�͵���Ϣ��ʽ����
{
    //data area Ҫ����ĸ�����Ϣ
    string bs_uuID;   //ID
    int bs_x;        //x����
    int bs_y;        //y����
    int src_index;   //���
    double signal;    //����ĸ�������
    string info;      //������ַ���
    double send_time;   //����ʱ��
    
    //data signature  ��������������Ϣ��ǩ��
    string data_sig;
    
    //signature certificate  ǩ��֤��
    string sig_srcid;      //���ͽڵ��ID
    string sig_srccomkey;  //ǩ����Կ
    string sig_CAid;       //��֤CA��ID
    string sig_CAsig;      //��֤CA��ǩ��
    int sig_srcIndex;      //��֤CA�ı��
    int sig_type;
    
    //encryption certificate ����֤��
    string enc_srcid;       //�ڵ�ID
    string enc_srccomkey;   //���ܹ�Կ
    string enc_CAid;        //��֤CA��ID
    string enc_CAsig;       //��֤CA��ǩ��
}    

message certiMessage     //ֻ������ǩ��֤�����Ϣ
{
    string sig_srcid;
    string sig_srccomkey;  //ǩ����Կ
    string sig_CAid;
    string sig_CAsig;
    //
    int src_index;  //��������Ϣ�Ľ��
    int sig_srcIndex; //ǩ�����
    int sig_type; 
} 

message askRenewMessage//Դ��bs��CAѯ���Ƿ������Ŀ��bsͨ��
{
    int bs_src_index;     //Դ�˷��������bs
    int bs_search_index;  //Ҫ���ҵ�bs
    int CA_1_index;       //;����CA1
    int CA_2_index;      //;����CA2
}

message replyRenewMessage//�ϼ�CA�ظ����¼��Ľ��
{
    int bs_src_index;     //����Ҫ�ظ���bs
    int bs_search_index;  //Ҫ���ҵ�bs
    bool trust;           //�Ƿ����ͨ�ŵĽ��
    int CA_1_index;       //;����CA_1
    int CA_2_index; 	  //;����CA_2
}