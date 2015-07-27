//
// Generated file, do not edit! Created by nedtool 4.6 from notification/controlmessages/NA_notification_msg_struct.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "NA_notification_msg_struct_m.h"

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

Register_Class(NotificationMsg);

NotificationMsg::NotificationMsg(const char *name, int kind) : ::cPacket(name,kind)
{
    this->tipoMensaje_var = 0;
    this->longitudTotal_var = 0;
    this->idMensaje_var = 0;
    this->idSrc_var = 0;
    this->ttl_var = 0;
}

NotificationMsg::NotificationMsg(const NotificationMsg& other) : ::cPacket(other)
{
    copy(other);
}

NotificationMsg::~NotificationMsg()
{
}

NotificationMsg& NotificationMsg::operator=(const NotificationMsg& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void NotificationMsg::copy(const NotificationMsg& other)
{
    this->tipoMensaje_var = other.tipoMensaje_var;
    this->longitudTotal_var = other.longitudTotal_var;
    this->idMensaje_var = other.idMensaje_var;
    this->idSrc_var = other.idSrc_var;
    this->ttl_var = other.ttl_var;
}

void NotificationMsg::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->tipoMensaje_var);
    doPacking(b,this->longitudTotal_var);
    doPacking(b,this->idMensaje_var);
    doPacking(b,this->idSrc_var);
    doPacking(b,this->ttl_var);
}

void NotificationMsg::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->tipoMensaje_var);
    doUnpacking(b,this->longitudTotal_var);
    doUnpacking(b,this->idMensaje_var);
    doUnpacking(b,this->idSrc_var);
    doUnpacking(b,this->ttl_var);
}

uint8_t NotificationMsg::getTipoMensaje() const
{
    return tipoMensaje_var;
}

void NotificationMsg::setTipoMensaje(uint8_t tipoMensaje)
{
    this->tipoMensaje_var = tipoMensaje;
}

uint8_t NotificationMsg::getLongitudTotal() const
{
    return longitudTotal_var;
}

void NotificationMsg::setLongitudTotal(uint8_t longitudTotal)
{
    this->longitudTotal_var = longitudTotal;
}

uint32_t NotificationMsg::getIdMensaje() const
{
    return idMensaje_var;
}

void NotificationMsg::setIdMensaje(uint32_t idMensaje)
{
    this->idMensaje_var = idMensaje;
}

uint32_t NotificationMsg::getIdSrc() const
{
    return idSrc_var;
}

void NotificationMsg::setIdSrc(uint32_t idSrc)
{
    this->idSrc_var = idSrc;
}

uint8_t NotificationMsg::getTtl() const
{
    return ttl_var;
}

void NotificationMsg::setTtl(uint8_t ttl)
{
    this->ttl_var = ttl;
}

class NotificationMsgDescriptor : public cClassDescriptor
{
  public:
    NotificationMsgDescriptor();
    virtual ~NotificationMsgDescriptor();

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

Register_ClassDescriptor(NotificationMsgDescriptor);

NotificationMsgDescriptor::NotificationMsgDescriptor() : cClassDescriptor("NotificationMsg", "cPacket")
{
}

NotificationMsgDescriptor::~NotificationMsgDescriptor()
{
}

bool NotificationMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<NotificationMsg *>(obj)!=NULL;
}

const char *NotificationMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int NotificationMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int NotificationMsgDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *NotificationMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "tipoMensaje",
        "longitudTotal",
        "idMensaje",
        "idSrc",
        "ttl",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int NotificationMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "tipoMensaje")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "longitudTotal")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "idMensaje")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "idSrc")==0) return base+3;
    if (fieldName[0]=='t' && strcmp(fieldName, "ttl")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *NotificationMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",
        "uint8_t",
        "uint32_t",
        "uint32_t",
        "uint8_t",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *NotificationMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int NotificationMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    NotificationMsg *pp = (NotificationMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string NotificationMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    NotificationMsg *pp = (NotificationMsg *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getTipoMensaje());
        case 1: return ulong2string(pp->getLongitudTotal());
        case 2: return ulong2string(pp->getIdMensaje());
        case 3: return ulong2string(pp->getIdSrc());
        case 4: return ulong2string(pp->getTtl());
        default: return "";
    }
}

bool NotificationMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    NotificationMsg *pp = (NotificationMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setTipoMensaje(string2ulong(value)); return true;
        case 1: pp->setLongitudTotal(string2ulong(value)); return true;
        case 2: pp->setIdMensaje(string2ulong(value)); return true;
        case 3: pp->setIdSrc(string2ulong(value)); return true;
        case 4: pp->setTtl(string2ulong(value)); return true;
        default: return false;
    }
}

const char *NotificationMsgDescriptor::getFieldStructName(void *object, int field) const
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

void *NotificationMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    NotificationMsg *pp = (NotificationMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

AlertMsg_extension::AlertMsg_extension()
{
    tipo = 0;
    longitud = 0;
    datos = 0;
}

void doPacking(cCommBuffer *b, AlertMsg_extension& a)
{
    doPacking(b,a.tipo);
    doPacking(b,a.longitud);
    doPacking(b,a.datos);
}

void doUnpacking(cCommBuffer *b, AlertMsg_extension& a)
{
    doUnpacking(b,a.tipo);
    doUnpacking(b,a.longitud);
    doUnpacking(b,a.datos);
}

class AlertMsg_extensionDescriptor : public cClassDescriptor
{
  public:
    AlertMsg_extensionDescriptor();
    virtual ~AlertMsg_extensionDescriptor();

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

Register_ClassDescriptor(AlertMsg_extensionDescriptor);

AlertMsg_extensionDescriptor::AlertMsg_extensionDescriptor() : cClassDescriptor("AlertMsg_extension", "")
{
}

AlertMsg_extensionDescriptor::~AlertMsg_extensionDescriptor()
{
}

bool AlertMsg_extensionDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<AlertMsg_extension *>(obj)!=NULL;
}

const char *AlertMsg_extensionDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int AlertMsg_extensionDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int AlertMsg_extensionDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *AlertMsg_extensionDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "tipo",
        "longitud",
        "datos",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int AlertMsg_extensionDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "tipo")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "longitud")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "datos")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *AlertMsg_extensionDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",
        "uint8_t",
        "uint8_t",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *AlertMsg_extensionDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int AlertMsg_extensionDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    AlertMsg_extension *pp = (AlertMsg_extension *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string AlertMsg_extensionDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    AlertMsg_extension *pp = (AlertMsg_extension *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->tipo);
        case 1: return ulong2string(pp->longitud);
        case 2: return ulong2string(pp->datos);
        default: return "";
    }
}

bool AlertMsg_extensionDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    AlertMsg_extension *pp = (AlertMsg_extension *)object; (void)pp;
    switch (field) {
        case 0: pp->tipo = string2ulong(value); return true;
        case 1: pp->longitud = string2ulong(value); return true;
        case 2: pp->datos = string2ulong(value); return true;
        default: return false;
    }
}

const char *AlertMsg_extensionDescriptor::getFieldStructName(void *object, int field) const
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

void *AlertMsg_extensionDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    AlertMsg_extension *pp = (AlertMsg_extension *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(AlertMsg);

AlertMsg::AlertMsg(const char *name, int kind) : ::NotificationMsg(name,kind)
{
    this->evento_var = 0;
    this->severidad_var = 0;
    this->confiabilidad_var = 0;
    this->idMalicioso_var = 0;
    this->marcaTemporal_var = 0;
    alertExtension_arraysize = 0;
    this->alertExtension_var = 0;
}

AlertMsg::AlertMsg(const AlertMsg& other) : ::NotificationMsg(other)
{
    alertExtension_arraysize = 0;
    this->alertExtension_var = 0;
    copy(other);
}

AlertMsg::~AlertMsg()
{
    delete [] alertExtension_var;
}

AlertMsg& AlertMsg::operator=(const AlertMsg& other)
{
    if (this==&other) return *this;
    ::NotificationMsg::operator=(other);
    copy(other);
    return *this;
}

void AlertMsg::copy(const AlertMsg& other)
{
    this->evento_var = other.evento_var;
    this->severidad_var = other.severidad_var;
    this->confiabilidad_var = other.confiabilidad_var;
    this->idMalicioso_var = other.idMalicioso_var;
    this->marcaTemporal_var = other.marcaTemporal_var;
    delete [] this->alertExtension_var;
    this->alertExtension_var = (other.alertExtension_arraysize==0) ? NULL : new AlertMsg_extension[other.alertExtension_arraysize];
    alertExtension_arraysize = other.alertExtension_arraysize;
    for (unsigned int i=0; i<alertExtension_arraysize; i++)
        this->alertExtension_var[i] = other.alertExtension_var[i];
}

void AlertMsg::parsimPack(cCommBuffer *b)
{
    ::NotificationMsg::parsimPack(b);
    doPacking(b,this->evento_var);
    doPacking(b,this->severidad_var);
    doPacking(b,this->confiabilidad_var);
    doPacking(b,this->idMalicioso_var);
    doPacking(b,this->marcaTemporal_var);
    b->pack(alertExtension_arraysize);
    doPacking(b,this->alertExtension_var,alertExtension_arraysize);
}

void AlertMsg::parsimUnpack(cCommBuffer *b)
{
    ::NotificationMsg::parsimUnpack(b);
    doUnpacking(b,this->evento_var);
    doUnpacking(b,this->severidad_var);
    doUnpacking(b,this->confiabilidad_var);
    doUnpacking(b,this->idMalicioso_var);
    doUnpacking(b,this->marcaTemporal_var);
    delete [] this->alertExtension_var;
    b->unpack(alertExtension_arraysize);
    if (alertExtension_arraysize==0) {
        this->alertExtension_var = 0;
    } else {
        this->alertExtension_var = new AlertMsg_extension[alertExtension_arraysize];
        doUnpacking(b,this->alertExtension_var,alertExtension_arraysize);
    }
}

uint8_t AlertMsg::getEvento() const
{
    return evento_var;
}

void AlertMsg::setEvento(uint8_t evento)
{
    this->evento_var = evento;
}

uint8_t AlertMsg::getSeveridad() const
{
    return severidad_var;
}

void AlertMsg::setSeveridad(uint8_t severidad)
{
    this->severidad_var = severidad;
}

uint8_t AlertMsg::getConfiabilidad() const
{
    return confiabilidad_var;
}

void AlertMsg::setConfiabilidad(uint8_t confiabilidad)
{
    this->confiabilidad_var = confiabilidad;
}

uint32_t AlertMsg::getIdMalicioso() const
{
    return idMalicioso_var;
}

void AlertMsg::setIdMalicioso(uint32_t idMalicioso)
{
    this->idMalicioso_var = idMalicioso;
}

double AlertMsg::getMarcaTemporal() const
{
    return marcaTemporal_var;
}

void AlertMsg::setMarcaTemporal(double marcaTemporal)
{
    this->marcaTemporal_var = marcaTemporal;
}

void AlertMsg::setAlertExtensionArraySize(unsigned int size)
{
    AlertMsg_extension *alertExtension_var2 = (size==0) ? NULL : new AlertMsg_extension[size];
    unsigned int sz = alertExtension_arraysize < size ? alertExtension_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        alertExtension_var2[i] = this->alertExtension_var[i];
    alertExtension_arraysize = size;
    delete [] this->alertExtension_var;
    this->alertExtension_var = alertExtension_var2;
}

unsigned int AlertMsg::getAlertExtensionArraySize() const
{
    return alertExtension_arraysize;
}

AlertMsg_extension& AlertMsg::getAlertExtension(unsigned int k)
{
    if (k>=alertExtension_arraysize) throw cRuntimeError("Array of size %d indexed by %d", alertExtension_arraysize, k);
    return alertExtension_var[k];
}

void AlertMsg::setAlertExtension(unsigned int k, const AlertMsg_extension& alertExtension)
{
    if (k>=alertExtension_arraysize) throw cRuntimeError("Array of size %d indexed by %d", alertExtension_arraysize, k);
    this->alertExtension_var[k] = alertExtension;
}

class AlertMsgDescriptor : public cClassDescriptor
{
  public:
    AlertMsgDescriptor();
    virtual ~AlertMsgDescriptor();

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

Register_ClassDescriptor(AlertMsgDescriptor);

AlertMsgDescriptor::AlertMsgDescriptor() : cClassDescriptor("AlertMsg", "NotificationMsg")
{
}

AlertMsgDescriptor::~AlertMsgDescriptor()
{
}

bool AlertMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<AlertMsg *>(obj)!=NULL;
}

const char *AlertMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int AlertMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int AlertMsgDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *AlertMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "evento",
        "severidad",
        "confiabilidad",
        "idMalicioso",
        "marcaTemporal",
        "alertExtension",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int AlertMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "evento")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "severidad")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "confiabilidad")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "idMalicioso")==0) return base+3;
    if (fieldName[0]=='m' && strcmp(fieldName, "marcaTemporal")==0) return base+4;
    if (fieldName[0]=='a' && strcmp(fieldName, "alertExtension")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *AlertMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",
        "uint8_t",
        "uint8_t",
        "uint32_t",
        "double",
        "AlertMsg_extension",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *AlertMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int AlertMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    AlertMsg *pp = (AlertMsg *)object; (void)pp;
    switch (field) {
        case 5: return pp->getAlertExtensionArraySize();
        default: return 0;
    }
}

std::string AlertMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    AlertMsg *pp = (AlertMsg *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getEvento());
        case 1: return ulong2string(pp->getSeveridad());
        case 2: return ulong2string(pp->getConfiabilidad());
        case 3: return ulong2string(pp->getIdMalicioso());
        case 4: return double2string(pp->getMarcaTemporal());
        case 5: {std::stringstream out; out << pp->getAlertExtension(i); return out.str();}
        default: return "";
    }
}

bool AlertMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    AlertMsg *pp = (AlertMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setEvento(string2ulong(value)); return true;
        case 1: pp->setSeveridad(string2ulong(value)); return true;
        case 2: pp->setConfiabilidad(string2ulong(value)); return true;
        case 3: pp->setIdMalicioso(string2ulong(value)); return true;
        case 4: pp->setMarcaTemporal(string2double(value)); return true;
        default: return false;
    }
}

const char *AlertMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 5: return opp_typename(typeid(AlertMsg_extension));
        default: return NULL;
    };
}

void *AlertMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    AlertMsg *pp = (AlertMsg *)object; (void)pp;
    switch (field) {
        case 5: return (void *)(&pp->getAlertExtension(i)); break;
        default: return NULL;
    }
}

Register_Class(AlertMsgAdaptation);

AlertMsgAdaptation::AlertMsgAdaptation(const char *name, int kind) : ::NotificationMsg(name,kind)
{
    this->evento_var = 0;
    this->severidad_var = 0;
    this->confiabilidad_var = 0;
    this->maliciousNode_var = 0;
    this->marcaTemporal_var = 0;
    alertExtension_arraysize = 0;
    this->alertExtension_var = 0;
}

AlertMsgAdaptation::AlertMsgAdaptation(const AlertMsgAdaptation& other) : ::NotificationMsg(other)
{
    alertExtension_arraysize = 0;
    this->alertExtension_var = 0;
    copy(other);
}

AlertMsgAdaptation::~AlertMsgAdaptation()
{
    delete [] alertExtension_var;
}

AlertMsgAdaptation& AlertMsgAdaptation::operator=(const AlertMsgAdaptation& other)
{
    if (this==&other) return *this;
    ::NotificationMsg::operator=(other);
    copy(other);
    return *this;
}

void AlertMsgAdaptation::copy(const AlertMsgAdaptation& other)
{
    this->evento_var = other.evento_var;
    this->severidad_var = other.severidad_var;
    this->confiabilidad_var = other.confiabilidad_var;
    this->maliciousNode_var = other.maliciousNode_var;
    this->marcaTemporal_var = other.marcaTemporal_var;
    delete [] this->alertExtension_var;
    this->alertExtension_var = (other.alertExtension_arraysize==0) ? NULL : new AlertMsg_extension[other.alertExtension_arraysize];
    alertExtension_arraysize = other.alertExtension_arraysize;
    for (unsigned int i=0; i<alertExtension_arraysize; i++)
        this->alertExtension_var[i] = other.alertExtension_var[i];
}

void AlertMsgAdaptation::parsimPack(cCommBuffer *b)
{
    ::NotificationMsg::parsimPack(b);
    doPacking(b,this->evento_var);
    doPacking(b,this->severidad_var);
    doPacking(b,this->confiabilidad_var);
    doPacking(b,this->maliciousNode_var);
    doPacking(b,this->marcaTemporal_var);
    b->pack(alertExtension_arraysize);
    doPacking(b,this->alertExtension_var,alertExtension_arraysize);
}

void AlertMsgAdaptation::parsimUnpack(cCommBuffer *b)
{
    ::NotificationMsg::parsimUnpack(b);
    doUnpacking(b,this->evento_var);
    doUnpacking(b,this->severidad_var);
    doUnpacking(b,this->confiabilidad_var);
    doUnpacking(b,this->maliciousNode_var);
    doUnpacking(b,this->marcaTemporal_var);
    delete [] this->alertExtension_var;
    b->unpack(alertExtension_arraysize);
    if (alertExtension_arraysize==0) {
        this->alertExtension_var = 0;
    } else {
        this->alertExtension_var = new AlertMsg_extension[alertExtension_arraysize];
        doUnpacking(b,this->alertExtension_var,alertExtension_arraysize);
    }
}

uint8_t AlertMsgAdaptation::getEvento() const
{
    return evento_var;
}

void AlertMsgAdaptation::setEvento(uint8_t evento)
{
    this->evento_var = evento;
}

uint8_t AlertMsgAdaptation::getSeveridad() const
{
    return severidad_var;
}

void AlertMsgAdaptation::setSeveridad(uint8_t severidad)
{
    this->severidad_var = severidad;
}

uint8_t AlertMsgAdaptation::getConfiabilidad() const
{
    return confiabilidad_var;
}

void AlertMsgAdaptation::setConfiabilidad(uint8_t confiabilidad)
{
    this->confiabilidad_var = confiabilidad;
}

const char * AlertMsgAdaptation::getMaliciousNode() const
{
    return maliciousNode_var.c_str();
}

void AlertMsgAdaptation::setMaliciousNode(const char * maliciousNode)
{
    this->maliciousNode_var = maliciousNode;
}

double AlertMsgAdaptation::getMarcaTemporal() const
{
    return marcaTemporal_var;
}

void AlertMsgAdaptation::setMarcaTemporal(double marcaTemporal)
{
    this->marcaTemporal_var = marcaTemporal;
}

void AlertMsgAdaptation::setAlertExtensionArraySize(unsigned int size)
{
    AlertMsg_extension *alertExtension_var2 = (size==0) ? NULL : new AlertMsg_extension[size];
    unsigned int sz = alertExtension_arraysize < size ? alertExtension_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        alertExtension_var2[i] = this->alertExtension_var[i];
    alertExtension_arraysize = size;
    delete [] this->alertExtension_var;
    this->alertExtension_var = alertExtension_var2;
}

unsigned int AlertMsgAdaptation::getAlertExtensionArraySize() const
{
    return alertExtension_arraysize;
}

AlertMsg_extension& AlertMsgAdaptation::getAlertExtension(unsigned int k)
{
    if (k>=alertExtension_arraysize) throw cRuntimeError("Array of size %d indexed by %d", alertExtension_arraysize, k);
    return alertExtension_var[k];
}

void AlertMsgAdaptation::setAlertExtension(unsigned int k, const AlertMsg_extension& alertExtension)
{
    if (k>=alertExtension_arraysize) throw cRuntimeError("Array of size %d indexed by %d", alertExtension_arraysize, k);
    this->alertExtension_var[k] = alertExtension;
}

class AlertMsgAdaptationDescriptor : public cClassDescriptor
{
  public:
    AlertMsgAdaptationDescriptor();
    virtual ~AlertMsgAdaptationDescriptor();

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

Register_ClassDescriptor(AlertMsgAdaptationDescriptor);

AlertMsgAdaptationDescriptor::AlertMsgAdaptationDescriptor() : cClassDescriptor("AlertMsgAdaptation", "NotificationMsg")
{
}

AlertMsgAdaptationDescriptor::~AlertMsgAdaptationDescriptor()
{
}

bool AlertMsgAdaptationDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<AlertMsgAdaptation *>(obj)!=NULL;
}

const char *AlertMsgAdaptationDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int AlertMsgAdaptationDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int AlertMsgAdaptationDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *AlertMsgAdaptationDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "evento",
        "severidad",
        "confiabilidad",
        "maliciousNode",
        "marcaTemporal",
        "alertExtension",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int AlertMsgAdaptationDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "evento")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "severidad")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "confiabilidad")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "maliciousNode")==0) return base+3;
    if (fieldName[0]=='m' && strcmp(fieldName, "marcaTemporal")==0) return base+4;
    if (fieldName[0]=='a' && strcmp(fieldName, "alertExtension")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *AlertMsgAdaptationDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",
        "uint8_t",
        "uint8_t",
        "string",
        "double",
        "AlertMsg_extension",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *AlertMsgAdaptationDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int AlertMsgAdaptationDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    AlertMsgAdaptation *pp = (AlertMsgAdaptation *)object; (void)pp;
    switch (field) {
        case 5: return pp->getAlertExtensionArraySize();
        default: return 0;
    }
}

std::string AlertMsgAdaptationDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    AlertMsgAdaptation *pp = (AlertMsgAdaptation *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getEvento());
        case 1: return ulong2string(pp->getSeveridad());
        case 2: return ulong2string(pp->getConfiabilidad());
        case 3: return oppstring2string(pp->getMaliciousNode());
        case 4: return double2string(pp->getMarcaTemporal());
        case 5: {std::stringstream out; out << pp->getAlertExtension(i); return out.str();}
        default: return "";
    }
}

bool AlertMsgAdaptationDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    AlertMsgAdaptation *pp = (AlertMsgAdaptation *)object; (void)pp;
    switch (field) {
        case 0: pp->setEvento(string2ulong(value)); return true;
        case 1: pp->setSeveridad(string2ulong(value)); return true;
        case 2: pp->setConfiabilidad(string2ulong(value)); return true;
        case 3: pp->setMaliciousNode((value)); return true;
        case 4: pp->setMarcaTemporal(string2double(value)); return true;
        default: return false;
    }
}

const char *AlertMsgAdaptationDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 5: return opp_typename(typeid(AlertMsg_extension));
        default: return NULL;
    };
}

void *AlertMsgAdaptationDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    AlertMsgAdaptation *pp = (AlertMsgAdaptation *)object; (void)pp;
    switch (field) {
        case 5: return (void *)(&pp->getAlertExtension(i)); break;
        default: return NULL;
    }
}

REQMsg_extension::REQMsg_extension()
{
    idProtocolo = 0;
    idVariable = 0;
}

void doPacking(cCommBuffer *b, REQMsg_extension& a)
{
    doPacking(b,a.idProtocolo);
    doPacking(b,a.idVariable);
}

void doUnpacking(cCommBuffer *b, REQMsg_extension& a)
{
    doUnpacking(b,a.idProtocolo);
    doUnpacking(b,a.idVariable);
}

class REQMsg_extensionDescriptor : public cClassDescriptor
{
  public:
    REQMsg_extensionDescriptor();
    virtual ~REQMsg_extensionDescriptor();

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

Register_ClassDescriptor(REQMsg_extensionDescriptor);

REQMsg_extensionDescriptor::REQMsg_extensionDescriptor() : cClassDescriptor("REQMsg_extension", "")
{
}

REQMsg_extensionDescriptor::~REQMsg_extensionDescriptor()
{
}

bool REQMsg_extensionDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<REQMsg_extension *>(obj)!=NULL;
}

const char *REQMsg_extensionDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int REQMsg_extensionDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int REQMsg_extensionDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *REQMsg_extensionDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "idProtocolo",
        "idVariable",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int REQMsg_extensionDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "idProtocolo")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "idVariable")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *REQMsg_extensionDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",
        "uint32_t",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *REQMsg_extensionDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int REQMsg_extensionDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    REQMsg_extension *pp = (REQMsg_extension *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string REQMsg_extensionDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    REQMsg_extension *pp = (REQMsg_extension *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->idProtocolo);
        case 1: return ulong2string(pp->idVariable);
        default: return "";
    }
}

bool REQMsg_extensionDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    REQMsg_extension *pp = (REQMsg_extension *)object; (void)pp;
    switch (field) {
        case 0: pp->idProtocolo = string2ulong(value); return true;
        case 1: pp->idVariable = string2ulong(value); return true;
        default: return false;
    }
}

const char *REQMsg_extensionDescriptor::getFieldStructName(void *object, int field) const
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

void *REQMsg_extensionDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    REQMsg_extension *pp = (REQMsg_extension *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(REQMsg);

REQMsg::REQMsg(const char *name, int kind) : ::NotificationMsg(name,kind)
{
    this->nodos_var = 0;
    this->variables_var = 0;
    idNodoSolicitado_arraysize = 0;
    this->idNodoSolicitado_var = 0;
    reqExtension_arraysize = 0;
    this->reqExtension_var = 0;
}

REQMsg::REQMsg(const REQMsg& other) : ::NotificationMsg(other)
{
    idNodoSolicitado_arraysize = 0;
    this->idNodoSolicitado_var = 0;
    reqExtension_arraysize = 0;
    this->reqExtension_var = 0;
    copy(other);
}

REQMsg::~REQMsg()
{
    delete [] idNodoSolicitado_var;
    delete [] reqExtension_var;
}

REQMsg& REQMsg::operator=(const REQMsg& other)
{
    if (this==&other) return *this;
    ::NotificationMsg::operator=(other);
    copy(other);
    return *this;
}

void REQMsg::copy(const REQMsg& other)
{
    this->nodos_var = other.nodos_var;
    this->variables_var = other.variables_var;
    delete [] this->idNodoSolicitado_var;
    this->idNodoSolicitado_var = (other.idNodoSolicitado_arraysize==0) ? NULL : new uint32_t[other.idNodoSolicitado_arraysize];
    idNodoSolicitado_arraysize = other.idNodoSolicitado_arraysize;
    for (unsigned int i=0; i<idNodoSolicitado_arraysize; i++)
        this->idNodoSolicitado_var[i] = other.idNodoSolicitado_var[i];
    delete [] this->reqExtension_var;
    this->reqExtension_var = (other.reqExtension_arraysize==0) ? NULL : new REQMsg_extension[other.reqExtension_arraysize];
    reqExtension_arraysize = other.reqExtension_arraysize;
    for (unsigned int i=0; i<reqExtension_arraysize; i++)
        this->reqExtension_var[i] = other.reqExtension_var[i];
}

void REQMsg::parsimPack(cCommBuffer *b)
{
    ::NotificationMsg::parsimPack(b);
    doPacking(b,this->nodos_var);
    doPacking(b,this->variables_var);
    b->pack(idNodoSolicitado_arraysize);
    doPacking(b,this->idNodoSolicitado_var,idNodoSolicitado_arraysize);
    b->pack(reqExtension_arraysize);
    doPacking(b,this->reqExtension_var,reqExtension_arraysize);
}

void REQMsg::parsimUnpack(cCommBuffer *b)
{
    ::NotificationMsg::parsimUnpack(b);
    doUnpacking(b,this->nodos_var);
    doUnpacking(b,this->variables_var);
    delete [] this->idNodoSolicitado_var;
    b->unpack(idNodoSolicitado_arraysize);
    if (idNodoSolicitado_arraysize==0) {
        this->idNodoSolicitado_var = 0;
    } else {
        this->idNodoSolicitado_var = new uint32_t[idNodoSolicitado_arraysize];
        doUnpacking(b,this->idNodoSolicitado_var,idNodoSolicitado_arraysize);
    }
    delete [] this->reqExtension_var;
    b->unpack(reqExtension_arraysize);
    if (reqExtension_arraysize==0) {
        this->reqExtension_var = 0;
    } else {
        this->reqExtension_var = new REQMsg_extension[reqExtension_arraysize];
        doUnpacking(b,this->reqExtension_var,reqExtension_arraysize);
    }
}

uint16_t REQMsg::getNodos() const
{
    return nodos_var;
}

void REQMsg::setNodos(uint16_t nodos)
{
    this->nodos_var = nodos;
}

uint16_t REQMsg::getVariables() const
{
    return variables_var;
}

void REQMsg::setVariables(uint16_t variables)
{
    this->variables_var = variables;
}

void REQMsg::setIdNodoSolicitadoArraySize(unsigned int size)
{
    uint32_t *idNodoSolicitado_var2 = (size==0) ? NULL : new uint32_t[size];
    unsigned int sz = idNodoSolicitado_arraysize < size ? idNodoSolicitado_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        idNodoSolicitado_var2[i] = this->idNodoSolicitado_var[i];
    for (unsigned int i=sz; i<size; i++)
        idNodoSolicitado_var2[i] = 0;
    idNodoSolicitado_arraysize = size;
    delete [] this->idNodoSolicitado_var;
    this->idNodoSolicitado_var = idNodoSolicitado_var2;
}

unsigned int REQMsg::getIdNodoSolicitadoArraySize() const
{
    return idNodoSolicitado_arraysize;
}

uint32_t REQMsg::getIdNodoSolicitado(unsigned int k) const
{
    if (k>=idNodoSolicitado_arraysize) throw cRuntimeError("Array of size %d indexed by %d", idNodoSolicitado_arraysize, k);
    return idNodoSolicitado_var[k];
}

void REQMsg::setIdNodoSolicitado(unsigned int k, uint32_t idNodoSolicitado)
{
    if (k>=idNodoSolicitado_arraysize) throw cRuntimeError("Array of size %d indexed by %d", idNodoSolicitado_arraysize, k);
    this->idNodoSolicitado_var[k] = idNodoSolicitado;
}

void REQMsg::setReqExtensionArraySize(unsigned int size)
{
    REQMsg_extension *reqExtension_var2 = (size==0) ? NULL : new REQMsg_extension[size];
    unsigned int sz = reqExtension_arraysize < size ? reqExtension_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        reqExtension_var2[i] = this->reqExtension_var[i];
    reqExtension_arraysize = size;
    delete [] this->reqExtension_var;
    this->reqExtension_var = reqExtension_var2;
}

unsigned int REQMsg::getReqExtensionArraySize() const
{
    return reqExtension_arraysize;
}

REQMsg_extension& REQMsg::getReqExtension(unsigned int k)
{
    if (k>=reqExtension_arraysize) throw cRuntimeError("Array of size %d indexed by %d", reqExtension_arraysize, k);
    return reqExtension_var[k];
}

void REQMsg::setReqExtension(unsigned int k, const REQMsg_extension& reqExtension)
{
    if (k>=reqExtension_arraysize) throw cRuntimeError("Array of size %d indexed by %d", reqExtension_arraysize, k);
    this->reqExtension_var[k] = reqExtension;
}

class REQMsgDescriptor : public cClassDescriptor
{
  public:
    REQMsgDescriptor();
    virtual ~REQMsgDescriptor();

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

Register_ClassDescriptor(REQMsgDescriptor);

REQMsgDescriptor::REQMsgDescriptor() : cClassDescriptor("REQMsg", "NotificationMsg")
{
}

REQMsgDescriptor::~REQMsgDescriptor()
{
}

bool REQMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<REQMsg *>(obj)!=NULL;
}

const char *REQMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int REQMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int REQMsgDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *REQMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "nodos",
        "variables",
        "idNodoSolicitado",
        "reqExtension",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int REQMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "nodos")==0) return base+0;
    if (fieldName[0]=='v' && strcmp(fieldName, "variables")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "idNodoSolicitado")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "reqExtension")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *REQMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",
        "uint16_t",
        "uint32_t",
        "REQMsg_extension",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *REQMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int REQMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    REQMsg *pp = (REQMsg *)object; (void)pp;
    switch (field) {
        case 2: return pp->getIdNodoSolicitadoArraySize();
        case 3: return pp->getReqExtensionArraySize();
        default: return 0;
    }
}

std::string REQMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    REQMsg *pp = (REQMsg *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getNodos());
        case 1: return ulong2string(pp->getVariables());
        case 2: return ulong2string(pp->getIdNodoSolicitado(i));
        case 3: {std::stringstream out; out << pp->getReqExtension(i); return out.str();}
        default: return "";
    }
}

bool REQMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    REQMsg *pp = (REQMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setNodos(string2ulong(value)); return true;
        case 1: pp->setVariables(string2ulong(value)); return true;
        case 2: pp->setIdNodoSolicitado(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *REQMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 3: return opp_typename(typeid(REQMsg_extension));
        default: return NULL;
    };
}

void *REQMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    REQMsg *pp = (REQMsg *)object; (void)pp;
    switch (field) {
        case 3: return (void *)(&pp->getReqExtension(i)); break;
        default: return NULL;
    }
}

REPMsg_extension::REPMsg_extension()
{
    idProtocolo = 0;
    idVariable = 0;
    valorVariable = 0;
}

void doPacking(cCommBuffer *b, REPMsg_extension& a)
{
    doPacking(b,a.idProtocolo);
    doPacking(b,a.idVariable);
    doPacking(b,a.valorVariable);
}

void doUnpacking(cCommBuffer *b, REPMsg_extension& a)
{
    doUnpacking(b,a.idProtocolo);
    doUnpacking(b,a.idVariable);
    doUnpacking(b,a.valorVariable);
}

class REPMsg_extensionDescriptor : public cClassDescriptor
{
  public:
    REPMsg_extensionDescriptor();
    virtual ~REPMsg_extensionDescriptor();

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

Register_ClassDescriptor(REPMsg_extensionDescriptor);

REPMsg_extensionDescriptor::REPMsg_extensionDescriptor() : cClassDescriptor("REPMsg_extension", "")
{
}

REPMsg_extensionDescriptor::~REPMsg_extensionDescriptor()
{
}

bool REPMsg_extensionDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<REPMsg_extension *>(obj)!=NULL;
}

const char *REPMsg_extensionDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int REPMsg_extensionDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int REPMsg_extensionDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *REPMsg_extensionDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "idProtocolo",
        "idVariable",
        "valorVariable",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int REPMsg_extensionDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "idProtocolo")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "idVariable")==0) return base+1;
    if (fieldName[0]=='v' && strcmp(fieldName, "valorVariable")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *REPMsg_extensionDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",
        "uint32_t",
        "uint32_t",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *REPMsg_extensionDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int REPMsg_extensionDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    REPMsg_extension *pp = (REPMsg_extension *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string REPMsg_extensionDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    REPMsg_extension *pp = (REPMsg_extension *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->idProtocolo);
        case 1: return ulong2string(pp->idVariable);
        case 2: return ulong2string(pp->valorVariable);
        default: return "";
    }
}

bool REPMsg_extensionDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    REPMsg_extension *pp = (REPMsg_extension *)object; (void)pp;
    switch (field) {
        case 0: pp->idProtocolo = string2ulong(value); return true;
        case 1: pp->idVariable = string2ulong(value); return true;
        case 2: pp->valorVariable = string2ulong(value); return true;
        default: return false;
    }
}

const char *REPMsg_extensionDescriptor::getFieldStructName(void *object, int field) const
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

void *REPMsg_extensionDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    REPMsg_extension *pp = (REPMsg_extension *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(REPMsg);

REPMsg::REPMsg(const char *name, int kind) : ::NotificationMsg(name,kind)
{
    this->nodos_var = 0;
    this->variables_var = 0;
    this->idNodoSolicitante_var = 0;
    idNodoInformado_arraysize = 0;
    this->idNodoInformado_var = 0;
    repExtension_arraysize = 0;
    this->repExtension_var = 0;
}

REPMsg::REPMsg(const REPMsg& other) : ::NotificationMsg(other)
{
    idNodoInformado_arraysize = 0;
    this->idNodoInformado_var = 0;
    repExtension_arraysize = 0;
    this->repExtension_var = 0;
    copy(other);
}

REPMsg::~REPMsg()
{
    delete [] idNodoInformado_var;
    delete [] repExtension_var;
}

REPMsg& REPMsg::operator=(const REPMsg& other)
{
    if (this==&other) return *this;
    ::NotificationMsg::operator=(other);
    copy(other);
    return *this;
}

void REPMsg::copy(const REPMsg& other)
{
    this->nodos_var = other.nodos_var;
    this->variables_var = other.variables_var;
    this->idNodoSolicitante_var = other.idNodoSolicitante_var;
    delete [] this->idNodoInformado_var;
    this->idNodoInformado_var = (other.idNodoInformado_arraysize==0) ? NULL : new uint32_t[other.idNodoInformado_arraysize];
    idNodoInformado_arraysize = other.idNodoInformado_arraysize;
    for (unsigned int i=0; i<idNodoInformado_arraysize; i++)
        this->idNodoInformado_var[i] = other.idNodoInformado_var[i];
    delete [] this->repExtension_var;
    this->repExtension_var = (other.repExtension_arraysize==0) ? NULL : new REPMsg_extension[other.repExtension_arraysize];
    repExtension_arraysize = other.repExtension_arraysize;
    for (unsigned int i=0; i<repExtension_arraysize; i++)
        this->repExtension_var[i] = other.repExtension_var[i];
}

void REPMsg::parsimPack(cCommBuffer *b)
{
    ::NotificationMsg::parsimPack(b);
    doPacking(b,this->nodos_var);
    doPacking(b,this->variables_var);
    doPacking(b,this->idNodoSolicitante_var);
    b->pack(idNodoInformado_arraysize);
    doPacking(b,this->idNodoInformado_var,idNodoInformado_arraysize);
    b->pack(repExtension_arraysize);
    doPacking(b,this->repExtension_var,repExtension_arraysize);
}

void REPMsg::parsimUnpack(cCommBuffer *b)
{
    ::NotificationMsg::parsimUnpack(b);
    doUnpacking(b,this->nodos_var);
    doUnpacking(b,this->variables_var);
    doUnpacking(b,this->idNodoSolicitante_var);
    delete [] this->idNodoInformado_var;
    b->unpack(idNodoInformado_arraysize);
    if (idNodoInformado_arraysize==0) {
        this->idNodoInformado_var = 0;
    } else {
        this->idNodoInformado_var = new uint32_t[idNodoInformado_arraysize];
        doUnpacking(b,this->idNodoInformado_var,idNodoInformado_arraysize);
    }
    delete [] this->repExtension_var;
    b->unpack(repExtension_arraysize);
    if (repExtension_arraysize==0) {
        this->repExtension_var = 0;
    } else {
        this->repExtension_var = new REPMsg_extension[repExtension_arraysize];
        doUnpacking(b,this->repExtension_var,repExtension_arraysize);
    }
}

uint16_t REPMsg::getNodos() const
{
    return nodos_var;
}

void REPMsg::setNodos(uint16_t nodos)
{
    this->nodos_var = nodos;
}

uint16_t REPMsg::getVariables() const
{
    return variables_var;
}

void REPMsg::setVariables(uint16_t variables)
{
    this->variables_var = variables;
}

uint32_t REPMsg::getIdNodoSolicitante() const
{
    return idNodoSolicitante_var;
}

void REPMsg::setIdNodoSolicitante(uint32_t idNodoSolicitante)
{
    this->idNodoSolicitante_var = idNodoSolicitante;
}

void REPMsg::setIdNodoInformadoArraySize(unsigned int size)
{
    uint32_t *idNodoInformado_var2 = (size==0) ? NULL : new uint32_t[size];
    unsigned int sz = idNodoInformado_arraysize < size ? idNodoInformado_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        idNodoInformado_var2[i] = this->idNodoInformado_var[i];
    for (unsigned int i=sz; i<size; i++)
        idNodoInformado_var2[i] = 0;
    idNodoInformado_arraysize = size;
    delete [] this->idNodoInformado_var;
    this->idNodoInformado_var = idNodoInformado_var2;
}

unsigned int REPMsg::getIdNodoInformadoArraySize() const
{
    return idNodoInformado_arraysize;
}

uint32_t REPMsg::getIdNodoInformado(unsigned int k) const
{
    if (k>=idNodoInformado_arraysize) throw cRuntimeError("Array of size %d indexed by %d", idNodoInformado_arraysize, k);
    return idNodoInformado_var[k];
}

void REPMsg::setIdNodoInformado(unsigned int k, uint32_t idNodoInformado)
{
    if (k>=idNodoInformado_arraysize) throw cRuntimeError("Array of size %d indexed by %d", idNodoInformado_arraysize, k);
    this->idNodoInformado_var[k] = idNodoInformado;
}

void REPMsg::setRepExtensionArraySize(unsigned int size)
{
    REPMsg_extension *repExtension_var2 = (size==0) ? NULL : new REPMsg_extension[size];
    unsigned int sz = repExtension_arraysize < size ? repExtension_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        repExtension_var2[i] = this->repExtension_var[i];
    repExtension_arraysize = size;
    delete [] this->repExtension_var;
    this->repExtension_var = repExtension_var2;
}

unsigned int REPMsg::getRepExtensionArraySize() const
{
    return repExtension_arraysize;
}

REPMsg_extension& REPMsg::getRepExtension(unsigned int k)
{
    if (k>=repExtension_arraysize) throw cRuntimeError("Array of size %d indexed by %d", repExtension_arraysize, k);
    return repExtension_var[k];
}

void REPMsg::setRepExtension(unsigned int k, const REPMsg_extension& repExtension)
{
    if (k>=repExtension_arraysize) throw cRuntimeError("Array of size %d indexed by %d", repExtension_arraysize, k);
    this->repExtension_var[k] = repExtension;
}

class REPMsgDescriptor : public cClassDescriptor
{
  public:
    REPMsgDescriptor();
    virtual ~REPMsgDescriptor();

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

Register_ClassDescriptor(REPMsgDescriptor);

REPMsgDescriptor::REPMsgDescriptor() : cClassDescriptor("REPMsg", "NotificationMsg")
{
}

REPMsgDescriptor::~REPMsgDescriptor()
{
}

bool REPMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<REPMsg *>(obj)!=NULL;
}

const char *REPMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int REPMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int REPMsgDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *REPMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "nodos",
        "variables",
        "idNodoSolicitante",
        "idNodoInformado",
        "repExtension",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int REPMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "nodos")==0) return base+0;
    if (fieldName[0]=='v' && strcmp(fieldName, "variables")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "idNodoSolicitante")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "idNodoInformado")==0) return base+3;
    if (fieldName[0]=='r' && strcmp(fieldName, "repExtension")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *REPMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",
        "uint16_t",
        "uint32_t",
        "uint32_t",
        "REPMsg_extension",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *REPMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int REPMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    REPMsg *pp = (REPMsg *)object; (void)pp;
    switch (field) {
        case 3: return pp->getIdNodoInformadoArraySize();
        case 4: return pp->getRepExtensionArraySize();
        default: return 0;
    }
}

std::string REPMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    REPMsg *pp = (REPMsg *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getNodos());
        case 1: return ulong2string(pp->getVariables());
        case 2: return ulong2string(pp->getIdNodoSolicitante());
        case 3: return ulong2string(pp->getIdNodoInformado(i));
        case 4: {std::stringstream out; out << pp->getRepExtension(i); return out.str();}
        default: return "";
    }
}

bool REPMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    REPMsg *pp = (REPMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setNodos(string2ulong(value)); return true;
        case 1: pp->setVariables(string2ulong(value)); return true;
        case 2: pp->setIdNodoSolicitante(string2ulong(value)); return true;
        case 3: pp->setIdNodoInformado(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *REPMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 4: return opp_typename(typeid(REPMsg_extension));
        default: return NULL;
    };
}

void *REPMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    REPMsg *pp = (REPMsg *)object; (void)pp;
    switch (field) {
        case 4: return (void *)(&pp->getRepExtension(i)); break;
        default: return NULL;
    }
}


