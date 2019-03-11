#pragma once

#include <omnetpp.h>
#include <string>
#include "sensedsignal_m.h"

struct signatureCerti{  //签名证书
    std::string src_id;
    std::string src_comkey;  //签名公钥
    std::string CA_id;
    std::string CA_sig;
};

struct encryptionCerti{  //加密证书
    std::string src_id;
    std::string src_comkey;   //加密公钥
    std::string CA_id;
    std::string CA_sig;
};

