//
// Generated file, do not edit! Created by nedtool 4.6 from detection/controlmessages/droppingDetectorDistributed/NA_DroppingDetectorDistributedMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "NA_DroppingDetectorDistributedMessage_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

Register_Class(NA_DroppingDetectorDistributedMessage);

NA_DroppingDetectorDistributedMessage::NA_DroppingDetectorDistributedMessage(const char *name, int kind) : ::cMessage(name,kind)
{
    this->timestamp_var = 0;
    this->RTS_var = 0;
    this->CTS_var = 0;
    this->DATA_var = 0;
    this->RREQ_var = 0;
    this->SrcIPAdd_var = 0;
    this->DstIPAdd_var = 0;
    this->SrcMACAdd_var = 0;
    this->DstMACAdd_var = 0;
    this->OrgAdd_var = 0;
    this->index_var = 0;
}

NA_DroppingDetectorDistributedMessage::NA_DroppingDetectorDistributedMessage(const NA_DroppingDetectorDistributedMessage& other) : ::cMessage(other)
{
    copy(other);
}

NA_DroppingDetectorDistributedMessage::~NA_DroppingDetectorDistributedMessage()
{
}

NA_DroppingDetectorDistributedMessage& NA_DroppingDetectorDistributedMessage::operator=(const NA_DroppingDetectorDistributedMessage& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void NA_DroppingDetectorDistributedMessage::copy(const NA_DroppingDetectorDistributedMessage& other)
{
    this->timestamp_var = other.timestamp_var;
    this->RTS_var = other.RTS_var;
    this->CTS_var = other.CTS_var;
    this->DATA_var = other.DATA_var;
    this->RREQ_var = other.RREQ_var;
    this->SrcIPAdd_var = other.SrcIPAdd_var;
    this->DstIPAdd_var = other.DstIPAdd_var;
    this->SrcMACAdd_var = other.SrcMACAdd_var;
    this->DstMACAdd_var = other.DstMACAdd_var;
    this->OrgAdd_var = other.OrgAdd_var;
    this->index_var = other.index_var;
}

void NA_DroppingDetectorDistributedMessage::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->timestamp_var);
    doPacking(b,this->RTS_var);
    doPacking(b,this->CTS_var);
    doPacking(b,this->DATA_var);
    doPacking(b,this->RREQ_var);
    doPacking(b,this->SrcIPAdd_var);
    doPacking(b,this->DstIPAdd_var);
    doPacking(b,this->SrcMACAdd_var);
    doPacking(b,this->DstMACAdd_var);
    doPacking(b,this->OrgAdd_var);
    doPacking(b,this->index_var);
}

void NA_DroppingDetectorDistributedMessage::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->timestamp_var);
    doUnpacking(b,this->RTS_var);
    doUnpacking(b,this->CTS_var);
    doUnpacking(b,this->DATA_var);
    doUnpacking(b,this->RREQ_var);
    doUnpacking(b,this->SrcIPAdd_var);
    doUnpacking(b,this->DstIPAdd_var);
    doUnpacking(b,this->SrcMACAdd_var);
    doUnpacking(b,this->DstMACAdd_var);
    doUnpacking(b,this->OrgAdd_var);
    doUnpacking(b,this->index_var);
}

simtime_t NA_DroppingDetectorDistributedMessage::getTimestamp() const
{
    return timestamp_var;
}

void NA_DroppingDetectorDistributedMessage::setTimestamp(simtime_t timestamp)
{
    this->timestamp_var = timestamp;
}

bool NA_DroppingDetectorDistributedMessage::getRTS() const
{
    return RTS_var;
}

void NA_DroppingDetectorDistributedMessage::setRTS(bool RTS)
{
    this->RTS_var = RTS;
}

bool NA_DroppingDetectorDistributedMessage::getCTS() const
{
    return CTS_var;
}

void NA_DroppingDetectorDistributedMessage::setCTS(bool CTS)
{
    this->CTS_var = CTS;
}

bool NA_DroppingDetectorDistributedMessage::getDATA() const
{
    return DATA_var;
}

void NA_DroppingDetectorDistributedMessage::setDATA(bool DATA)
{
    this->DATA_var = DATA;
}

bool NA_DroppingDetectorDistributedMessage::getRREQ() const
{
    return RREQ_var;
}

void NA_DroppingDetectorDistributedMessage::setRREQ(bool RREQ)
{
    this->RREQ_var = RREQ;
}

uint32_t NA_DroppingDetectorDistributedMessage::getSrcIPAdd() const
{
    return SrcIPAdd_var;
}

void NA_DroppingDetectorDistributedMessage::setSrcIPAdd(uint32_t SrcIPAdd)
{
    this->SrcIPAdd_var = SrcIPAdd;
}

uint32_t NA_DroppingDetectorDistributedMessage::getDstIPAdd() const
{
    return DstIPAdd_var;
}

void NA_DroppingDetectorDistributedMessage::setDstIPAdd(uint32_t DstIPAdd)
{
    this->DstIPAdd_var = DstIPAdd;
}

uint64_t NA_DroppingDetectorDistributedMessage::getSrcMACAdd() const
{
    return SrcMACAdd_var;
}

void NA_DroppingDetectorDistributedMessage::setSrcMACAdd(uint64_t SrcMACAdd)
{
    this->SrcMACAdd_var = SrcMACAdd;
}

uint64_t NA_DroppingDetectorDistributedMessage::getDstMACAdd() const
{
    return DstMACAdd_var;
}

void NA_DroppingDetectorDistributedMessage::setDstMACAdd(uint64_t DstMACAdd)
{
    this->DstMACAdd_var = DstMACAdd;
}

uint32_t NA_DroppingDetectorDistributedMessage::getOrgAdd() const
{
    return OrgAdd_var;
}

void NA_DroppingDetectorDistributedMessage::setOrgAdd(uint32_t OrgAdd)
{
    this->OrgAdd_var = OrgAdd;
}

int NA_DroppingDetectorDistributedMessage::getIndex() const
{
    return index_var;
}

void NA_DroppingDetectorDistributedMessage::setIndex(int index)
{
    this->index_var = index;
}

class NA_DroppingDetectorDistributedMessageDescriptor : public cClassDescriptor
{
  public:
    NA_DroppingDetectorDistributedMessageDescriptor();
    virtual ~NA_DroppingDetectorDistributedMessageDescriptor();

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

Register_ClassDescriptor(NA_DroppingDetectorDistributedMessageDescriptor);

NA_DroppingDetectorDistributedMessageDescriptor::NA_DroppingDetectorDistributedMessageDescriptor() : cClassDescriptor("NA_DroppingDetectorDistributedMessage", "cMessage")
{
}

NA_DroppingDetectorDistributedMessageDescriptor::~NA_DroppingDetectorDistributedMessageDescriptor()
{
}

bool NA_DroppingDetectorDistributedMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<NA_DroppingDetectorDistributedMessage *>(obj)!=NULL;
}

const char *NA_DroppingDetectorDistributedMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int NA_DroppingDetectorDistributedMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 11+basedesc->getFieldCount(object) : 11;
}

unsigned int NA_DroppingDetectorDistributedMessageDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<11) ? fieldTypeFlags[field] : 0;
}

const char *NA_DroppingDetectorDistributedMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "timestamp",
        "RTS",
        "CTS",
        "DATA",
        "RREQ",
        "SrcIPAdd",
        "DstIPAdd",
        "SrcMACAdd",
        "DstMACAdd",
        "OrgAdd",
        "index",
    };
    return (field>=0 && field<11) ? fieldNames[field] : NULL;
}

int NA_DroppingDetectorDistributedMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "timestamp")==0) return base+0;
    if (fieldName[0]=='R' && strcmp(fieldName, "RTS")==0) return base+1;
    if (fieldName[0]=='C' && strcmp(fieldName, "CTS")==0) return base+2;
    if (fieldName[0]=='D' && strcmp(fieldName, "DATA")==0) return base+3;
    if (fieldName[0]=='R' && strcmp(fieldName, "RREQ")==0) return base+4;
    if (fieldName[0]=='S' && strcmp(fieldName, "SrcIPAdd")==0) return base+5;
    if (fieldName[0]=='D' && strcmp(fieldName, "DstIPAdd")==0) return base+6;
    if (fieldName[0]=='S' && strcmp(fieldName, "SrcMACAdd")==0) return base+7;
    if (fieldName[0]=='D' && strcmp(fieldName, "DstMACAdd")==0) return base+8;
    if (fieldName[0]=='O' && strcmp(fieldName, "OrgAdd")==0) return base+9;
    if (fieldName[0]=='i' && strcmp(fieldName, "index")==0) return base+10;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *NA_DroppingDetectorDistributedMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "simtime_t",
        "bool",
        "bool",
        "bool",
        "bool",
        "uint32_t",
        "uint32_t",
        "uint64_t",
        "uint64_t",
        "uint32_t",
        "int",
    };
    return (field>=0 && field<11) ? fieldTypeStrings[field] : NULL;
}

const char *NA_DroppingDetectorDistributedMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int NA_DroppingDetectorDistributedMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    NA_DroppingDetectorDistributedMessage *pp = (NA_DroppingDetectorDistributedMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string NA_DroppingDetectorDistributedMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    NA_DroppingDetectorDistributedMessage *pp = (NA_DroppingDetectorDistributedMessage *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getTimestamp());
        case 1: return bool2string(pp->getRTS());
        case 2: return bool2string(pp->getCTS());
        case 3: return bool2string(pp->getDATA());
        case 4: return bool2string(pp->getRREQ());
        case 5: return ulong2string(pp->getSrcIPAdd());
        case 6: return ulong2string(pp->getDstIPAdd());
        case 7: return uint642string(pp->getSrcMACAdd());
        case 8: return uint642string(pp->getDstMACAdd());
        case 9: return ulong2string(pp->getOrgAdd());
        case 10: return long2string(pp->getIndex());
        default: return "";
    }
}

bool NA_DroppingDetectorDistributedMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    NA_DroppingDetectorDistributedMessage *pp = (NA_DroppingDetectorDistributedMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setTimestamp(string2double(value)); return true;
        case 1: pp->setRTS(string2bool(value)); return true;
        case 2: pp->setCTS(string2bool(value)); return true;
        case 3: pp->setDATA(string2bool(value)); return true;
        case 4: pp->setRREQ(string2bool(value)); return true;
        case 5: pp->setSrcIPAdd(string2ulong(value)); return true;
        case 6: pp->setDstIPAdd(string2ulong(value)); return true;
        case 7: pp->setSrcMACAdd(string2uint64(value)); return true;
        case 8: pp->setDstMACAdd(string2uint64(value)); return true;
        case 9: pp->setOrgAdd(string2ulong(value)); return true;
        case 10: pp->setIndex(string2long(value)); return true;
        default: return false;
    }
}

const char *NA_DroppingDetectorDistributedMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *NA_DroppingDetectorDistributedMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    NA_DroppingDetectorDistributedMessage *pp = (NA_DroppingDetectorDistributedMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


