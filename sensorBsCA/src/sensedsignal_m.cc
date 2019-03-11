//
// Generated file, do not edit! Created by opp_msgc 4.4 from sensedsignal.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "sensedsignal_m.h"

USING_NAMESPACE

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




Register_Class(SensorMessage);

SensorMessage::SensorMessage(const char *name, int kind) : ::cMessage(name,kind)
{
    this->sensor_uuID_var = 0;
    this->sensor_index_var = 0;
    this->sensor_xPos_var = 0;
    this->sensor_yPos_var = 0;
    this->bs_uuID_var = 0;
    this->bs_index_var = 0;
    this->action_var = 0;
    this->sensor_signal_var = 0;
    this->send_time_var = 0;
}

SensorMessage::SensorMessage(const SensorMessage& other) : ::cMessage(other)
{
    copy(other);
}

SensorMessage::~SensorMessage()
{
}

SensorMessage& SensorMessage::operator=(const SensorMessage& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void SensorMessage::copy(const SensorMessage& other)
{
    this->sensor_uuID_var = other.sensor_uuID_var;
    this->sensor_index_var = other.sensor_index_var;
    this->sensor_xPos_var = other.sensor_xPos_var;
    this->sensor_yPos_var = other.sensor_yPos_var;
    this->bs_uuID_var = other.bs_uuID_var;
    this->bs_index_var = other.bs_index_var;
    this->action_var = other.action_var;
    this->sensor_signal_var = other.sensor_signal_var;
    this->send_time_var = other.send_time_var;
}

void SensorMessage::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->sensor_uuID_var);
    doPacking(b,this->sensor_index_var);
    doPacking(b,this->sensor_xPos_var);
    doPacking(b,this->sensor_yPos_var);
    doPacking(b,this->bs_uuID_var);
    doPacking(b,this->bs_index_var);
    doPacking(b,this->action_var);
    doPacking(b,this->sensor_signal_var);
    doPacking(b,this->send_time_var);
}

void SensorMessage::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->sensor_uuID_var);
    doUnpacking(b,this->sensor_index_var);
    doUnpacking(b,this->sensor_xPos_var);
    doUnpacking(b,this->sensor_yPos_var);
    doUnpacking(b,this->bs_uuID_var);
    doUnpacking(b,this->bs_index_var);
    doUnpacking(b,this->action_var);
    doUnpacking(b,this->sensor_signal_var);
    doUnpacking(b,this->send_time_var);
}

const char * SensorMessage::getSensor_uuID() const
{
    return sensor_uuID_var.c_str();
}

void SensorMessage::setSensor_uuID(const char * sensor_uuID)
{
    this->sensor_uuID_var = sensor_uuID;
}

int SensorMessage::getSensor_index() const
{
    return sensor_index_var;
}

void SensorMessage::setSensor_index(int sensor_index)
{
    this->sensor_index_var = sensor_index;
}

int SensorMessage::getSensor_xPos() const
{
    return sensor_xPos_var;
}

void SensorMessage::setSensor_xPos(int sensor_xPos)
{
    this->sensor_xPos_var = sensor_xPos;
}

int SensorMessage::getSensor_yPos() const
{
    return sensor_yPos_var;
}

void SensorMessage::setSensor_yPos(int sensor_yPos)
{
    this->sensor_yPos_var = sensor_yPos;
}

const char * SensorMessage::getBs_uuID() const
{
    return bs_uuID_var.c_str();
}

void SensorMessage::setBs_uuID(const char * bs_uuID)
{
    this->bs_uuID_var = bs_uuID;
}

int SensorMessage::getBs_index() const
{
    return bs_index_var;
}

void SensorMessage::setBs_index(int bs_index)
{
    this->bs_index_var = bs_index;
}

const char * SensorMessage::getAction() const
{
    return action_var.c_str();
}

void SensorMessage::setAction(const char * action)
{
    this->action_var = action;
}

double SensorMessage::getSensor_signal() const
{
    return sensor_signal_var;
}

void SensorMessage::setSensor_signal(double sensor_signal)
{
    this->sensor_signal_var = sensor_signal;
}

double SensorMessage::getSend_time() const
{
    return send_time_var;
}

void SensorMessage::setSend_time(double send_time)
{
    this->send_time_var = send_time;
}

class SensorMessageDescriptor : public cClassDescriptor
{
  public:
    SensorMessageDescriptor();
    virtual ~SensorMessageDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(SensorMessageDescriptor);

SensorMessageDescriptor::SensorMessageDescriptor() : cClassDescriptor("SensorMessage", "cMessage")
{
}

SensorMessageDescriptor::~SensorMessageDescriptor()
{
}

bool SensorMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SensorMessage *>(obj)!=NULL;
}

const char *SensorMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SensorMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount(object) : 9;
}

unsigned int SensorMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<9) ? fieldTypeFlags[field] : 0;
}

const char *SensorMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "sensor_uuID",
        "sensor_index",
        "sensor_xPos",
        "sensor_yPos",
        "bs_uuID",
        "bs_index",
        "action",
        "sensor_signal",
        "send_time",
    };
    return (field>=0 && field<9) ? fieldNames[field] : NULL;
}

int SensorMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sensor_uuID")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sensor_index")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sensor_xPos")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "sensor_yPos")==0) return base+3;
    if (fieldName[0]=='b' && strcmp(fieldName, "bs_uuID")==0) return base+4;
    if (fieldName[0]=='b' && strcmp(fieldName, "bs_index")==0) return base+5;
    if (fieldName[0]=='a' && strcmp(fieldName, "action")==0) return base+6;
    if (fieldName[0]=='s' && strcmp(fieldName, "sensor_signal")==0) return base+7;
    if (fieldName[0]=='s' && strcmp(fieldName, "send_time")==0) return base+8;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SensorMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "int",
        "int",
        "int",
        "string",
        "int",
        "string",
        "double",
        "double",
    };
    return (field>=0 && field<9) ? fieldTypeStrings[field] : NULL;
}

const char *SensorMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int SensorMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SensorMessage *pp = (SensorMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SensorMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SensorMessage *pp = (SensorMessage *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSensor_uuID());
        case 1: return long2string(pp->getSensor_index());
        case 2: return long2string(pp->getSensor_xPos());
        case 3: return long2string(pp->getSensor_yPos());
        case 4: return oppstring2string(pp->getBs_uuID());
        case 5: return long2string(pp->getBs_index());
        case 6: return oppstring2string(pp->getAction());
        case 7: return double2string(pp->getSensor_signal());
        case 8: return double2string(pp->getSend_time());
        default: return "";
    }
}

bool SensorMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SensorMessage *pp = (SensorMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setSensor_uuID((value)); return true;
        case 1: pp->setSensor_index(string2long(value)); return true;
        case 2: pp->setSensor_xPos(string2long(value)); return true;
        case 3: pp->setSensor_yPos(string2long(value)); return true;
        case 4: pp->setBs_uuID((value)); return true;
        case 5: pp->setBs_index(string2long(value)); return true;
        case 6: pp->setAction((value)); return true;
        case 7: pp->setSensor_signal(string2double(value)); return true;
        case 8: pp->setSend_time(string2double(value)); return true;
        default: return false;
    }
}

const char *SensorMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<9) ? fieldStructNames[field] : NULL;
}

void *SensorMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SensorMessage *pp = (SensorMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(generalMessage);

generalMessage::generalMessage(const char *name, int kind) : ::cMessage(name,kind)
{
    this->bs_uuID_var = 0;
    this->bs_x_var = 0;
    this->bs_y_var = 0;
    this->src_index_var = 0;
    this->signal_var = 0;
    this->info_var = 0;
    this->send_time_var = 0;
    this->data_sig_var = 0;
    this->sig_srcid_var = 0;
    this->sig_srccomkey_var = 0;
    this->sig_CAid_var = 0;
    this->sig_CAsig_var = 0;
    this->sig_srcIndex_var = 0;
    this->sig_type_var = 0;
    this->enc_srcid_var = 0;
    this->enc_srccomkey_var = 0;
    this->enc_CAid_var = 0;
    this->enc_CAsig_var = 0;
}

generalMessage::generalMessage(const generalMessage& other) : ::cMessage(other)
{
    copy(other);
}

generalMessage::~generalMessage()
{
}

generalMessage& generalMessage::operator=(const generalMessage& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void generalMessage::copy(const generalMessage& other)
{
    this->bs_uuID_var = other.bs_uuID_var;
    this->bs_x_var = other.bs_x_var;
    this->bs_y_var = other.bs_y_var;
    this->src_index_var = other.src_index_var;
    this->signal_var = other.signal_var;
    this->info_var = other.info_var;
    this->send_time_var = other.send_time_var;
    this->data_sig_var = other.data_sig_var;
    this->sig_srcid_var = other.sig_srcid_var;
    this->sig_srccomkey_var = other.sig_srccomkey_var;
    this->sig_CAid_var = other.sig_CAid_var;
    this->sig_CAsig_var = other.sig_CAsig_var;
    this->sig_srcIndex_var = other.sig_srcIndex_var;
    this->sig_type_var = other.sig_type_var;
    this->enc_srcid_var = other.enc_srcid_var;
    this->enc_srccomkey_var = other.enc_srccomkey_var;
    this->enc_CAid_var = other.enc_CAid_var;
    this->enc_CAsig_var = other.enc_CAsig_var;
}

void generalMessage::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->bs_uuID_var);
    doPacking(b,this->bs_x_var);
    doPacking(b,this->bs_y_var);
    doPacking(b,this->src_index_var);
    doPacking(b,this->signal_var);
    doPacking(b,this->info_var);
    doPacking(b,this->send_time_var);
    doPacking(b,this->data_sig_var);
    doPacking(b,this->sig_srcid_var);
    doPacking(b,this->sig_srccomkey_var);
    doPacking(b,this->sig_CAid_var);
    doPacking(b,this->sig_CAsig_var);
    doPacking(b,this->sig_srcIndex_var);
    doPacking(b,this->sig_type_var);
    doPacking(b,this->enc_srcid_var);
    doPacking(b,this->enc_srccomkey_var);
    doPacking(b,this->enc_CAid_var);
    doPacking(b,this->enc_CAsig_var);
}

void generalMessage::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->bs_uuID_var);
    doUnpacking(b,this->bs_x_var);
    doUnpacking(b,this->bs_y_var);
    doUnpacking(b,this->src_index_var);
    doUnpacking(b,this->signal_var);
    doUnpacking(b,this->info_var);
    doUnpacking(b,this->send_time_var);
    doUnpacking(b,this->data_sig_var);
    doUnpacking(b,this->sig_srcid_var);
    doUnpacking(b,this->sig_srccomkey_var);
    doUnpacking(b,this->sig_CAid_var);
    doUnpacking(b,this->sig_CAsig_var);
    doUnpacking(b,this->sig_srcIndex_var);
    doUnpacking(b,this->sig_type_var);
    doUnpacking(b,this->enc_srcid_var);
    doUnpacking(b,this->enc_srccomkey_var);
    doUnpacking(b,this->enc_CAid_var);
    doUnpacking(b,this->enc_CAsig_var);
}

const char * generalMessage::getBs_uuID() const
{
    return bs_uuID_var.c_str();
}

void generalMessage::setBs_uuID(const char * bs_uuID)
{
    this->bs_uuID_var = bs_uuID;
}

int generalMessage::getBs_x() const
{
    return bs_x_var;
}

void generalMessage::setBs_x(int bs_x)
{
    this->bs_x_var = bs_x;
}

int generalMessage::getBs_y() const
{
    return bs_y_var;
}

void generalMessage::setBs_y(int bs_y)
{
    this->bs_y_var = bs_y;
}

int generalMessage::getSrc_index() const
{
    return src_index_var;
}

void generalMessage::setSrc_index(int src_index)
{
    this->src_index_var = src_index;
}

double generalMessage::getSignal() const
{
    return signal_var;
}

void generalMessage::setSignal(double signal)
{
    this->signal_var = signal;
}

const char * generalMessage::getInfo() const
{
    return info_var.c_str();
}

void generalMessage::setInfo(const char * info)
{
    this->info_var = info;
}

double generalMessage::getSend_time() const
{
    return send_time_var;
}

void generalMessage::setSend_time(double send_time)
{
    this->send_time_var = send_time;
}

const char * generalMessage::getData_sig() const
{
    return data_sig_var.c_str();
}

void generalMessage::setData_sig(const char * data_sig)
{
    this->data_sig_var = data_sig;
}

const char * generalMessage::getSig_srcid() const
{
    return sig_srcid_var.c_str();
}

void generalMessage::setSig_srcid(const char * sig_srcid)
{
    this->sig_srcid_var = sig_srcid;
}

const char * generalMessage::getSig_srccomkey() const
{
    return sig_srccomkey_var.c_str();
}

void generalMessage::setSig_srccomkey(const char * sig_srccomkey)
{
    this->sig_srccomkey_var = sig_srccomkey;
}

const char * generalMessage::getSig_CAid() const
{
    return sig_CAid_var.c_str();
}

void generalMessage::setSig_CAid(const char * sig_CAid)
{
    this->sig_CAid_var = sig_CAid;
}

const char * generalMessage::getSig_CAsig() const
{
    return sig_CAsig_var.c_str();
}

void generalMessage::setSig_CAsig(const char * sig_CAsig)
{
    this->sig_CAsig_var = sig_CAsig;
}

int generalMessage::getSig_srcIndex() const
{
    return sig_srcIndex_var;
}

void generalMessage::setSig_srcIndex(int sig_srcIndex)
{
    this->sig_srcIndex_var = sig_srcIndex;
}

int generalMessage::getSig_type() const
{
    return sig_type_var;
}

void generalMessage::setSig_type(int sig_type)
{
    this->sig_type_var = sig_type;
}

const char * generalMessage::getEnc_srcid() const
{
    return enc_srcid_var.c_str();
}

void generalMessage::setEnc_srcid(const char * enc_srcid)
{
    this->enc_srcid_var = enc_srcid;
}

const char * generalMessage::getEnc_srccomkey() const
{
    return enc_srccomkey_var.c_str();
}

void generalMessage::setEnc_srccomkey(const char * enc_srccomkey)
{
    this->enc_srccomkey_var = enc_srccomkey;
}

const char * generalMessage::getEnc_CAid() const
{
    return enc_CAid_var.c_str();
}

void generalMessage::setEnc_CAid(const char * enc_CAid)
{
    this->enc_CAid_var = enc_CAid;
}

const char * generalMessage::getEnc_CAsig() const
{
    return enc_CAsig_var.c_str();
}

void generalMessage::setEnc_CAsig(const char * enc_CAsig)
{
    this->enc_CAsig_var = enc_CAsig;
}

class generalMessageDescriptor : public cClassDescriptor
{
  public:
    generalMessageDescriptor();
    virtual ~generalMessageDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(generalMessageDescriptor);

generalMessageDescriptor::generalMessageDescriptor() : cClassDescriptor("generalMessage", "cMessage")
{
}

generalMessageDescriptor::~generalMessageDescriptor()
{
}

bool generalMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<generalMessage *>(obj)!=NULL;
}

const char *generalMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int generalMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 18+basedesc->getFieldCount(object) : 18;
}

unsigned int generalMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<18) ? fieldTypeFlags[field] : 0;
}

const char *generalMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "bs_uuID",
        "bs_x",
        "bs_y",
        "src_index",
        "signal",
        "info",
        "send_time",
        "data_sig",
        "sig_srcid",
        "sig_srccomkey",
        "sig_CAid",
        "sig_CAsig",
        "sig_srcIndex",
        "sig_type",
        "enc_srcid",
        "enc_srccomkey",
        "enc_CAid",
        "enc_CAsig",
    };
    return (field>=0 && field<18) ? fieldNames[field] : NULL;
}

int generalMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bs_uuID")==0) return base+0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bs_x")==0) return base+1;
    if (fieldName[0]=='b' && strcmp(fieldName, "bs_y")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "src_index")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "signal")==0) return base+4;
    if (fieldName[0]=='i' && strcmp(fieldName, "info")==0) return base+5;
    if (fieldName[0]=='s' && strcmp(fieldName, "send_time")==0) return base+6;
    if (fieldName[0]=='d' && strcmp(fieldName, "data_sig")==0) return base+7;
    if (fieldName[0]=='s' && strcmp(fieldName, "sig_srcid")==0) return base+8;
    if (fieldName[0]=='s' && strcmp(fieldName, "sig_srccomkey")==0) return base+9;
    if (fieldName[0]=='s' && strcmp(fieldName, "sig_CAid")==0) return base+10;
    if (fieldName[0]=='s' && strcmp(fieldName, "sig_CAsig")==0) return base+11;
    if (fieldName[0]=='s' && strcmp(fieldName, "sig_srcIndex")==0) return base+12;
    if (fieldName[0]=='s' && strcmp(fieldName, "sig_type")==0) return base+13;
    if (fieldName[0]=='e' && strcmp(fieldName, "enc_srcid")==0) return base+14;
    if (fieldName[0]=='e' && strcmp(fieldName, "enc_srccomkey")==0) return base+15;
    if (fieldName[0]=='e' && strcmp(fieldName, "enc_CAid")==0) return base+16;
    if (fieldName[0]=='e' && strcmp(fieldName, "enc_CAsig")==0) return base+17;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *generalMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "int",
        "int",
        "int",
        "double",
        "string",
        "double",
        "string",
        "string",
        "string",
        "string",
        "string",
        "int",
        "int",
        "string",
        "string",
        "string",
        "string",
    };
    return (field>=0 && field<18) ? fieldTypeStrings[field] : NULL;
}

const char *generalMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int generalMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    generalMessage *pp = (generalMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string generalMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    generalMessage *pp = (generalMessage *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getBs_uuID());
        case 1: return long2string(pp->getBs_x());
        case 2: return long2string(pp->getBs_y());
        case 3: return long2string(pp->getSrc_index());
        case 4: return double2string(pp->getSignal());
        case 5: return oppstring2string(pp->getInfo());
        case 6: return double2string(pp->getSend_time());
        case 7: return oppstring2string(pp->getData_sig());
        case 8: return oppstring2string(pp->getSig_srcid());
        case 9: return oppstring2string(pp->getSig_srccomkey());
        case 10: return oppstring2string(pp->getSig_CAid());
        case 11: return oppstring2string(pp->getSig_CAsig());
        case 12: return long2string(pp->getSig_srcIndex());
        case 13: return long2string(pp->getSig_type());
        case 14: return oppstring2string(pp->getEnc_srcid());
        case 15: return oppstring2string(pp->getEnc_srccomkey());
        case 16: return oppstring2string(pp->getEnc_CAid());
        case 17: return oppstring2string(pp->getEnc_CAsig());
        default: return "";
    }
}

bool generalMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    generalMessage *pp = (generalMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setBs_uuID((value)); return true;
        case 1: pp->setBs_x(string2long(value)); return true;
        case 2: pp->setBs_y(string2long(value)); return true;
        case 3: pp->setSrc_index(string2long(value)); return true;
        case 4: pp->setSignal(string2double(value)); return true;
        case 5: pp->setInfo((value)); return true;
        case 6: pp->setSend_time(string2double(value)); return true;
        case 7: pp->setData_sig((value)); return true;
        case 8: pp->setSig_srcid((value)); return true;
        case 9: pp->setSig_srccomkey((value)); return true;
        case 10: pp->setSig_CAid((value)); return true;
        case 11: pp->setSig_CAsig((value)); return true;
        case 12: pp->setSig_srcIndex(string2long(value)); return true;
        case 13: pp->setSig_type(string2long(value)); return true;
        case 14: pp->setEnc_srcid((value)); return true;
        case 15: pp->setEnc_srccomkey((value)); return true;
        case 16: pp->setEnc_CAid((value)); return true;
        case 17: pp->setEnc_CAsig((value)); return true;
        default: return false;
    }
}

const char *generalMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<18) ? fieldStructNames[field] : NULL;
}

void *generalMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    generalMessage *pp = (generalMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(certiMessage);

certiMessage::certiMessage(const char *name, int kind) : ::cMessage(name,kind)
{
    this->sig_srcid_var = 0;
    this->sig_srccomkey_var = 0;
    this->sig_CAid_var = 0;
    this->sig_CAsig_var = 0;
    this->src_index_var = 0;
    this->sig_srcIndex_var = 0;
    this->sig_type_var = 0;
}

certiMessage::certiMessage(const certiMessage& other) : ::cMessage(other)
{
    copy(other);
}

certiMessage::~certiMessage()
{
}

certiMessage& certiMessage::operator=(const certiMessage& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void certiMessage::copy(const certiMessage& other)
{
    this->sig_srcid_var = other.sig_srcid_var;
    this->sig_srccomkey_var = other.sig_srccomkey_var;
    this->sig_CAid_var = other.sig_CAid_var;
    this->sig_CAsig_var = other.sig_CAsig_var;
    this->src_index_var = other.src_index_var;
    this->sig_srcIndex_var = other.sig_srcIndex_var;
    this->sig_type_var = other.sig_type_var;
}

void certiMessage::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->sig_srcid_var);
    doPacking(b,this->sig_srccomkey_var);
    doPacking(b,this->sig_CAid_var);
    doPacking(b,this->sig_CAsig_var);
    doPacking(b,this->src_index_var);
    doPacking(b,this->sig_srcIndex_var);
    doPacking(b,this->sig_type_var);
}

void certiMessage::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->sig_srcid_var);
    doUnpacking(b,this->sig_srccomkey_var);
    doUnpacking(b,this->sig_CAid_var);
    doUnpacking(b,this->sig_CAsig_var);
    doUnpacking(b,this->src_index_var);
    doUnpacking(b,this->sig_srcIndex_var);
    doUnpacking(b,this->sig_type_var);
}

const char * certiMessage::getSig_srcid() const
{
    return sig_srcid_var.c_str();
}

void certiMessage::setSig_srcid(const char * sig_srcid)
{
    this->sig_srcid_var = sig_srcid;
}

const char * certiMessage::getSig_srccomkey() const
{
    return sig_srccomkey_var.c_str();
}

void certiMessage::setSig_srccomkey(const char * sig_srccomkey)
{
    this->sig_srccomkey_var = sig_srccomkey;
}

const char * certiMessage::getSig_CAid() const
{
    return sig_CAid_var.c_str();
}

void certiMessage::setSig_CAid(const char * sig_CAid)
{
    this->sig_CAid_var = sig_CAid;
}

const char * certiMessage::getSig_CAsig() const
{
    return sig_CAsig_var.c_str();
}

void certiMessage::setSig_CAsig(const char * sig_CAsig)
{
    this->sig_CAsig_var = sig_CAsig;
}

int certiMessage::getSrc_index() const
{
    return src_index_var;
}

void certiMessage::setSrc_index(int src_index)
{
    this->src_index_var = src_index;
}

int certiMessage::getSig_srcIndex() const
{
    return sig_srcIndex_var;
}

void certiMessage::setSig_srcIndex(int sig_srcIndex)
{
    this->sig_srcIndex_var = sig_srcIndex;
}

int certiMessage::getSig_type() const
{
    return sig_type_var;
}

void certiMessage::setSig_type(int sig_type)
{
    this->sig_type_var = sig_type;
}

class certiMessageDescriptor : public cClassDescriptor
{
  public:
    certiMessageDescriptor();
    virtual ~certiMessageDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(certiMessageDescriptor);

certiMessageDescriptor::certiMessageDescriptor() : cClassDescriptor("certiMessage", "cMessage")
{
}

certiMessageDescriptor::~certiMessageDescriptor()
{
}

bool certiMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<certiMessage *>(obj)!=NULL;
}

const char *certiMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int certiMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int certiMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *certiMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "sig_srcid",
        "sig_srccomkey",
        "sig_CAid",
        "sig_CAsig",
        "src_index",
        "sig_srcIndex",
        "sig_type",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int certiMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sig_srcid")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sig_srccomkey")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sig_CAid")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "sig_CAsig")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "src_index")==0) return base+4;
    if (fieldName[0]=='s' && strcmp(fieldName, "sig_srcIndex")==0) return base+5;
    if (fieldName[0]=='s' && strcmp(fieldName, "sig_type")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *certiMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "string",
        "string",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *certiMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int certiMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    certiMessage *pp = (certiMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string certiMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    certiMessage *pp = (certiMessage *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSig_srcid());
        case 1: return oppstring2string(pp->getSig_srccomkey());
        case 2: return oppstring2string(pp->getSig_CAid());
        case 3: return oppstring2string(pp->getSig_CAsig());
        case 4: return long2string(pp->getSrc_index());
        case 5: return long2string(pp->getSig_srcIndex());
        case 6: return long2string(pp->getSig_type());
        default: return "";
    }
}

bool certiMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    certiMessage *pp = (certiMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setSig_srcid((value)); return true;
        case 1: pp->setSig_srccomkey((value)); return true;
        case 2: pp->setSig_CAid((value)); return true;
        case 3: pp->setSig_CAsig((value)); return true;
        case 4: pp->setSrc_index(string2long(value)); return true;
        case 5: pp->setSig_srcIndex(string2long(value)); return true;
        case 6: pp->setSig_type(string2long(value)); return true;
        default: return false;
    }
}

const char *certiMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<7) ? fieldStructNames[field] : NULL;
}

void *certiMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    certiMessage *pp = (certiMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(askRenewMessage);

askRenewMessage::askRenewMessage(const char *name, int kind) : ::cMessage(name,kind)
{
    this->bs_src_index_var = 0;
    this->bs_search_index_var = 0;
    this->CA_1_index_var = 0;
    this->CA_2_index_var = 0;
}

askRenewMessage::askRenewMessage(const askRenewMessage& other) : ::cMessage(other)
{
    copy(other);
}

askRenewMessage::~askRenewMessage()
{
}

askRenewMessage& askRenewMessage::operator=(const askRenewMessage& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void askRenewMessage::copy(const askRenewMessage& other)
{
    this->bs_src_index_var = other.bs_src_index_var;
    this->bs_search_index_var = other.bs_search_index_var;
    this->CA_1_index_var = other.CA_1_index_var;
    this->CA_2_index_var = other.CA_2_index_var;
}

void askRenewMessage::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->bs_src_index_var);
    doPacking(b,this->bs_search_index_var);
    doPacking(b,this->CA_1_index_var);
    doPacking(b,this->CA_2_index_var);
}

void askRenewMessage::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->bs_src_index_var);
    doUnpacking(b,this->bs_search_index_var);
    doUnpacking(b,this->CA_1_index_var);
    doUnpacking(b,this->CA_2_index_var);
}

int askRenewMessage::getBs_src_index() const
{
    return bs_src_index_var;
}

void askRenewMessage::setBs_src_index(int bs_src_index)
{
    this->bs_src_index_var = bs_src_index;
}

int askRenewMessage::getBs_search_index() const
{
    return bs_search_index_var;
}

void askRenewMessage::setBs_search_index(int bs_search_index)
{
    this->bs_search_index_var = bs_search_index;
}

int askRenewMessage::getCA_1_index() const
{
    return CA_1_index_var;
}

void askRenewMessage::setCA_1_index(int CA_1_index)
{
    this->CA_1_index_var = CA_1_index;
}

int askRenewMessage::getCA_2_index() const
{
    return CA_2_index_var;
}

void askRenewMessage::setCA_2_index(int CA_2_index)
{
    this->CA_2_index_var = CA_2_index;
}

class askRenewMessageDescriptor : public cClassDescriptor
{
  public:
    askRenewMessageDescriptor();
    virtual ~askRenewMessageDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(askRenewMessageDescriptor);

askRenewMessageDescriptor::askRenewMessageDescriptor() : cClassDescriptor("askRenewMessage", "cMessage")
{
}

askRenewMessageDescriptor::~askRenewMessageDescriptor()
{
}

bool askRenewMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<askRenewMessage *>(obj)!=NULL;
}

const char *askRenewMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int askRenewMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int askRenewMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *askRenewMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "bs_src_index",
        "bs_search_index",
        "CA_1_index",
        "CA_2_index",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int askRenewMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bs_src_index")==0) return base+0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bs_search_index")==0) return base+1;
    if (fieldName[0]=='C' && strcmp(fieldName, "CA_1_index")==0) return base+2;
    if (fieldName[0]=='C' && strcmp(fieldName, "CA_2_index")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *askRenewMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *askRenewMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int askRenewMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    askRenewMessage *pp = (askRenewMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string askRenewMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    askRenewMessage *pp = (askRenewMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getBs_src_index());
        case 1: return long2string(pp->getBs_search_index());
        case 2: return long2string(pp->getCA_1_index());
        case 3: return long2string(pp->getCA_2_index());
        default: return "";
    }
}

bool askRenewMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    askRenewMessage *pp = (askRenewMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setBs_src_index(string2long(value)); return true;
        case 1: pp->setBs_search_index(string2long(value)); return true;
        case 2: pp->setCA_1_index(string2long(value)); return true;
        case 3: pp->setCA_2_index(string2long(value)); return true;
        default: return false;
    }
}

const char *askRenewMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *askRenewMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    askRenewMessage *pp = (askRenewMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(replyRenewMessage);

replyRenewMessage::replyRenewMessage(const char *name, int kind) : ::cMessage(name,kind)
{
    this->bs_src_index_var = 0;
    this->bs_search_index_var = 0;
    this->trust_var = 0;
    this->CA_1_index_var = 0;
    this->CA_2_index_var = 0;
}

replyRenewMessage::replyRenewMessage(const replyRenewMessage& other) : ::cMessage(other)
{
    copy(other);
}

replyRenewMessage::~replyRenewMessage()
{
}

replyRenewMessage& replyRenewMessage::operator=(const replyRenewMessage& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void replyRenewMessage::copy(const replyRenewMessage& other)
{
    this->bs_src_index_var = other.bs_src_index_var;
    this->bs_search_index_var = other.bs_search_index_var;
    this->trust_var = other.trust_var;
    this->CA_1_index_var = other.CA_1_index_var;
    this->CA_2_index_var = other.CA_2_index_var;
}

void replyRenewMessage::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->bs_src_index_var);
    doPacking(b,this->bs_search_index_var);
    doPacking(b,this->trust_var);
    doPacking(b,this->CA_1_index_var);
    doPacking(b,this->CA_2_index_var);
}

void replyRenewMessage::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->bs_src_index_var);
    doUnpacking(b,this->bs_search_index_var);
    doUnpacking(b,this->trust_var);
    doUnpacking(b,this->CA_1_index_var);
    doUnpacking(b,this->CA_2_index_var);
}

int replyRenewMessage::getBs_src_index() const
{
    return bs_src_index_var;
}

void replyRenewMessage::setBs_src_index(int bs_src_index)
{
    this->bs_src_index_var = bs_src_index;
}

int replyRenewMessage::getBs_search_index() const
{
    return bs_search_index_var;
}

void replyRenewMessage::setBs_search_index(int bs_search_index)
{
    this->bs_search_index_var = bs_search_index;
}

bool replyRenewMessage::getTrust() const
{
    return trust_var;
}

void replyRenewMessage::setTrust(bool trust)
{
    this->trust_var = trust;
}

int replyRenewMessage::getCA_1_index() const
{
    return CA_1_index_var;
}

void replyRenewMessage::setCA_1_index(int CA_1_index)
{
    this->CA_1_index_var = CA_1_index;
}

int replyRenewMessage::getCA_2_index() const
{
    return CA_2_index_var;
}

void replyRenewMessage::setCA_2_index(int CA_2_index)
{
    this->CA_2_index_var = CA_2_index;
}

class replyRenewMessageDescriptor : public cClassDescriptor
{
  public:
    replyRenewMessageDescriptor();
    virtual ~replyRenewMessageDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(replyRenewMessageDescriptor);

replyRenewMessageDescriptor::replyRenewMessageDescriptor() : cClassDescriptor("replyRenewMessage", "cMessage")
{
}

replyRenewMessageDescriptor::~replyRenewMessageDescriptor()
{
}

bool replyRenewMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<replyRenewMessage *>(obj)!=NULL;
}

const char *replyRenewMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int replyRenewMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int replyRenewMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *replyRenewMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "bs_src_index",
        "bs_search_index",
        "trust",
        "CA_1_index",
        "CA_2_index",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int replyRenewMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bs_src_index")==0) return base+0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bs_search_index")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "trust")==0) return base+2;
    if (fieldName[0]=='C' && strcmp(fieldName, "CA_1_index")==0) return base+3;
    if (fieldName[0]=='C' && strcmp(fieldName, "CA_2_index")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *replyRenewMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "bool",
        "int",
        "int",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *replyRenewMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int replyRenewMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    replyRenewMessage *pp = (replyRenewMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string replyRenewMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    replyRenewMessage *pp = (replyRenewMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getBs_src_index());
        case 1: return long2string(pp->getBs_search_index());
        case 2: return bool2string(pp->getTrust());
        case 3: return long2string(pp->getCA_1_index());
        case 4: return long2string(pp->getCA_2_index());
        default: return "";
    }
}

bool replyRenewMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    replyRenewMessage *pp = (replyRenewMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setBs_src_index(string2long(value)); return true;
        case 1: pp->setBs_search_index(string2long(value)); return true;
        case 2: pp->setTrust(string2bool(value)); return true;
        case 3: pp->setCA_1_index(string2long(value)); return true;
        case 4: pp->setCA_2_index(string2long(value)); return true;
        default: return false;
    }
}

const char *replyRenewMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *replyRenewMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    replyRenewMessage *pp = (replyRenewMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


