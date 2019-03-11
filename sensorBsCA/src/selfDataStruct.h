#pragma once

#include <omnetpp.h>
#include <string>
#include "sensedsignal_m.h"

struct signatureCerti{  //ǩ��֤��
    std::string src_id;
    std::string src_comkey;  //ǩ����Կ
    std::string CA_id;
    std::string CA_sig;
};

struct encryptionCerti{  //����֤��
    std::string src_id;
    std::string src_comkey;   //���ܹ�Կ
    std::string CA_id;
    std::string CA_sig;
};

