//
// Generated file, do not edit! Created by nedtool 4.6 from detection/controlmessages/droppingDetectorStandalone/NA_DroppingDetectorStandaloneMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "NA_DroppingDetectorStandaloneMessage_m.h"

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

Register_Class(NA_DroppingDetectorStandaloneMessage);

NA_DroppingDetectorStandaloneMessage::NA_DroppingDetectorStandaloneMessage(const char *name, int kind) : ::cMessage(name,kind)
{
    this->SentRTS_var = 0;
    this->ReceivedCTS_var = 0;
    this->pMob_var = 0;
    this->FordwardedCount_var = 0;
    this->ReceivedCount_var = 0;
    this->RREQCount_var = 0;
    this->EventWindowSize_var = 0;
}

NA_DroppingDetectorStandaloneMessage::NA_DroppingDetectorStandaloneMessage(const NA_DroppingDetectorStandaloneMessage& other) : ::cMessage(other)
{
    copy(other);
}

NA_DroppingDetectorStandaloneMessage::~NA_DroppingDetectorStandaloneMessage()
{
}

NA_DroppingDetectorStandaloneMessage& NA_DroppingDetectorStandaloneMessage::operator=(const NA_DroppingDetectorStandaloneMessage& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void NA_DroppingDetectorStandaloneMessage::copy(const NA_DroppingDetectorStandaloneMessage& other)
{
    this->SentRTS_var = other.SentRTS_var;
    this->ReceivedCTS_var = other.ReceivedCTS_var;
    this->pMob_var = other.pMob_var;
    this->FordwardedCount_var = other.FordwardedCount_var;
    this->ReceivedCount_var = other.ReceivedCount_var;
    this->RREQCount_var = other.RREQCount_var;
    this->EventWindowSize_var = other.EventWindowSize_var;
}

void NA_DroppingDetectorStandaloneMessage::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->SentRTS_var);
    doPacking(b,this->ReceivedCTS_var);
    doPacking(b,this->pMob_var);
    doPacking(b,this->FordwardedCount_var);
    doPacking(b,this->ReceivedCount_var);
    doPacking(b,this->RREQCount_var);
    doPacking(b,this->EventWindowSize_var);
}

void NA_DroppingDetectorStandaloneMessage::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->SentRTS_var);
    doUnpacking(b,this->ReceivedCTS_var);
    doUnpacking(b,this->pMob_var);
    doUnpacking(b,this->FordwardedCount_var);
    doUnpacking(b,this->ReceivedCount_var);
    doUnpacking(b,this->RREQCount_var);
    doUnpacking(b,this->EventWindowSize_var);
}

long NA_DroppingDetectorStandaloneMessage::getSentRTS() const
{
    return SentRTS_var;
}

void NA_DroppingDetectorStandaloneMessage::setSentRTS(long SentRTS)
{
    this->SentRTS_var = SentRTS;
}

long NA_DroppingDetectorStandaloneMessage::getReceivedCTS() const
{
    return ReceivedCTS_var;
}

void NA_DroppingDetectorStandaloneMessage::setReceivedCTS(long ReceivedCTS)
{
    this->ReceivedCTS_var = ReceivedCTS;
}

long NA_DroppingDetectorStandaloneMessage::getPMob() const
{
    return pMob_var;
}

void NA_DroppingDetectorStandaloneMessage::setPMob(long pMob)
{
    this->pMob_var = pMob;
}

long NA_DroppingDetectorStandaloneMessage::getFordwardedCount() const
{
    return FordwardedCount_var;
}

void NA_DroppingDetectorStandaloneMessage::setFordwardedCount(long FordwardedCount)
{
    this->FordwardedCount_var = FordwardedCount;
}

long NA_DroppingDetectorStandaloneMessage::getReceivedCount() const
{
    return ReceivedCount_var;
}

void NA_DroppingDetectorStandaloneMessage::setReceivedCount(long ReceivedCount)
{
    this->ReceivedCount_var = ReceivedCount;
}

long NA_DroppingDetectorStandaloneMessage::getRREQCount() const
{
    return RREQCount_var;
}

void NA_DroppingDetectorStandaloneMessage::setRREQCount(long RREQCount)
{
    this->RREQCount_var = RREQCount;
}

long NA_DroppingDetectorStandaloneMessage::getEventWindowSize() const
{
    return EventWindowSize_var;
}

void NA_DroppingDetectorStandaloneMessage::setEventWindowSize(long EventWindowSize)
{
    this->EventWindowSize_var = EventWindowSize;
}

class NA_DroppingDetectorStandaloneMessageDescriptor : public cClassDescriptor
{
  public:
    NA_DroppingDetectorStandaloneMessageDescriptor();
    virtual ~NA_DroppingDetectorStandaloneMessageDescriptor();

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

Register_ClassDescriptor(NA_DroppingDetectorStandaloneMessageDescriptor);

NA_DroppingDetectorStandaloneMessageDescriptor::NA_DroppingDetectorStandaloneMessageDescriptor() : cClassDescriptor("NA_DroppingDetectorStandaloneMessage", "cMessage")
{
}

NA_DroppingDetectorStandaloneMessageDescriptor::~NA_DroppingDetectorStandaloneMessageDescriptor()
{
}

bool NA_DroppingDetectorStandaloneMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<NA_DroppingDetectorStandaloneMessage *>(obj)!=NULL;
}

const char *NA_DroppingDetectorStandaloneMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int NA_DroppingDetectorStandaloneMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int NA_DroppingDetectorStandaloneMessageDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *NA_DroppingDetectorStandaloneMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "SentRTS",
        "ReceivedCTS",
        "pMob",
        "FordwardedCount",
        "ReceivedCount",
        "RREQCount",
        "EventWindowSize",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int NA_DroppingDetectorStandaloneMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='S' && strcmp(fieldName, "SentRTS")==0) return base+0;
    if (fieldName[0]=='R' && strcmp(fieldName, "ReceivedCTS")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "pMob")==0) return base+2;
    if (fieldName[0]=='F' && strcmp(fieldName, "FordwardedCount")==0) return base+3;
    if (fieldName[0]=='R' && strcmp(fieldName, "ReceivedCount")==0) return base+4;
    if (fieldName[0]=='R' && strcmp(fieldName, "RREQCount")==0) return base+5;
    if (fieldName[0]=='E' && strcmp(fieldName, "EventWindowSize")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *NA_DroppingDetectorStandaloneMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "long",
        "long",
        "long",
        "long",
        "long",
        "long",
        "long",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *NA_DroppingDetectorStandaloneMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int NA_DroppingDetectorStandaloneMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    NA_DroppingDetectorStandaloneMessage *pp = (NA_DroppingDetectorStandaloneMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string NA_DroppingDetectorStandaloneMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    NA_DroppingDetectorStandaloneMessage *pp = (NA_DroppingDetectorStandaloneMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSentRTS());
        case 1: return long2string(pp->getReceivedCTS());
        case 2: return long2string(pp->getPMob());
        case 3: return long2string(pp->getFordwardedCount());
        case 4: return long2string(pp->getReceivedCount());
        case 5: return long2string(pp->getRREQCount());
        case 6: return long2string(pp->getEventWindowSize());
        default: return "";
    }
}

bool NA_DroppingDetectorStandaloneMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    NA_DroppingDetectorStandaloneMessage *pp = (NA_DroppingDetectorStandaloneMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setSentRTS(string2long(value)); return true;
        case 1: pp->setReceivedCTS(string2long(value)); return true;
        case 2: pp->setPMob(string2long(value)); return true;
        case 3: pp->setFordwardedCount(string2long(value)); return true;
        case 4: pp->setReceivedCount(string2long(value)); return true;
        case 5: pp->setRREQCount(string2long(value)); return true;
        case 6: pp->setEventWindowSize(string2long(value)); return true;
        default: return false;
    }
}

const char *NA_DroppingDetectorStandaloneMessageDescriptor::getFieldStructName(void *object, int field) const
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

void *NA_DroppingDetectorStandaloneMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    NA_DroppingDetectorStandaloneMessage *pp = (NA_DroppingDetectorStandaloneMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


