//
// Generated file, do not edit! Created by opp_msgtool 6.0 from messages/DataPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "DataPacket_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

Register_Class(DataPacket)

DataPacket::DataPacket(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

DataPacket::DataPacket(const DataPacket& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

DataPacket::~DataPacket()
{
}

DataPacket& DataPacket::operator=(const DataPacket& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void DataPacket::copy(const DataPacket& other)
{
    this->srcNode = other.srcNode;
    this->dstNode = other.dstNode;
    this->ttl = other.ttl;
    this->lastRouter = other.lastRouter;
    this->l2 = other.l2;
    this->l3 = other.l3;
    this->l4 = other.l4;
    this->lastQueue = other.lastQueue;
    this->q2 = other.q2;
    this->q3 = other.q3;
    this->q4 = other.q4;
    this->q5 = other.q5;
    this->lastTS = other.lastTS;
    this->t2 = other.t2;
    this->t3 = other.t3;
    this->t4 = other.t4;
    this->t5 = other.t5;
    this->routing = other.routing;
}

void DataPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->srcNode);
    doParsimPacking(b,this->dstNode);
    doParsimPacking(b,this->ttl);
    doParsimPacking(b,this->lastRouter);
    doParsimPacking(b,this->l2);
    doParsimPacking(b,this->l3);
    doParsimPacking(b,this->l4);
    doParsimPacking(b,this->lastQueue);
    doParsimPacking(b,this->q2);
    doParsimPacking(b,this->q3);
    doParsimPacking(b,this->q4);
    doParsimPacking(b,this->q5);
    doParsimPacking(b,this->lastTS);
    doParsimPacking(b,this->t2);
    doParsimPacking(b,this->t3);
    doParsimPacking(b,this->t4);
    doParsimPacking(b,this->t5);
    doParsimPacking(b,this->routing);
}

void DataPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->srcNode);
    doParsimUnpacking(b,this->dstNode);
    doParsimUnpacking(b,this->ttl);
    doParsimUnpacking(b,this->lastRouter);
    doParsimUnpacking(b,this->l2);
    doParsimUnpacking(b,this->l3);
    doParsimUnpacking(b,this->l4);
    doParsimUnpacking(b,this->lastQueue);
    doParsimUnpacking(b,this->q2);
    doParsimUnpacking(b,this->q3);
    doParsimUnpacking(b,this->q4);
    doParsimUnpacking(b,this->q5);
    doParsimUnpacking(b,this->lastTS);
    doParsimUnpacking(b,this->t2);
    doParsimUnpacking(b,this->t3);
    doParsimUnpacking(b,this->t4);
    doParsimUnpacking(b,this->t5);
    doParsimUnpacking(b,this->routing);
}

int DataPacket::getSrcNode() const
{
    return this->srcNode;
}

void DataPacket::setSrcNode(int srcNode)
{
    this->srcNode = srcNode;
}

int DataPacket::getDstNode() const
{
    return this->dstNode;
}

void DataPacket::setDstNode(int dstNode)
{
    this->dstNode = dstNode;
}

int DataPacket::getTtl() const
{
    return this->ttl;
}

void DataPacket::setTtl(int ttl)
{
    this->ttl = ttl;
}

int DataPacket::getLastRouter() const
{
    return this->lastRouter;
}

void DataPacket::setLastRouter(int lastRouter)
{
    this->lastRouter = lastRouter;
}

int DataPacket::getL2() const
{
    return this->l2;
}

void DataPacket::setL2(int l2)
{
    this->l2 = l2;
}

int DataPacket::getL3() const
{
    return this->l3;
}

void DataPacket::setL3(int l3)
{
    this->l3 = l3;
}

int DataPacket::getL4() const
{
    return this->l4;
}

void DataPacket::setL4(int l4)
{
    this->l4 = l4;
}

int DataPacket::getLastQueue() const
{
    return this->lastQueue;
}

void DataPacket::setLastQueue(int lastQueue)
{
    this->lastQueue = lastQueue;
}

int DataPacket::getQ2() const
{
    return this->q2;
}

void DataPacket::setQ2(int q2)
{
    this->q2 = q2;
}

int DataPacket::getQ3() const
{
    return this->q3;
}

void DataPacket::setQ3(int q3)
{
    this->q3 = q3;
}

int DataPacket::getQ4() const
{
    return this->q4;
}

void DataPacket::setQ4(int q4)
{
    this->q4 = q4;
}

int DataPacket::getQ5() const
{
    return this->q5;
}

void DataPacket::setQ5(int q5)
{
    this->q5 = q5;
}

double DataPacket::getLastTS() const
{
    return this->lastTS;
}

void DataPacket::setLastTS(double lastTS)
{
    this->lastTS = lastTS;
}

double DataPacket::getT2() const
{
    return this->t2;
}

void DataPacket::setT2(double t2)
{
    this->t2 = t2;
}

double DataPacket::getT3() const
{
    return this->t3;
}

void DataPacket::setT3(double t3)
{
    this->t3 = t3;
}

double DataPacket::getT4() const
{
    return this->t4;
}

void DataPacket::setT4(double t4)
{
    this->t4 = t4;
}

double DataPacket::getT5() const
{
    return this->t5;
}

void DataPacket::setT5(double t5)
{
    this->t5 = t5;
}

int DataPacket::getRouting() const
{
    return this->routing;
}

void DataPacket::setRouting(int routing)
{
    this->routing = routing;
}

class DataPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_srcNode,
        FIELD_dstNode,
        FIELD_ttl,
        FIELD_lastRouter,
        FIELD_l2,
        FIELD_l3,
        FIELD_l4,
        FIELD_lastQueue,
        FIELD_q2,
        FIELD_q3,
        FIELD_q4,
        FIELD_q5,
        FIELD_lastTS,
        FIELD_t2,
        FIELD_t3,
        FIELD_t4,
        FIELD_t5,
        FIELD_routing,
    };
  public:
    DataPacketDescriptor();
    virtual ~DataPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(DataPacketDescriptor)

DataPacketDescriptor::DataPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(DataPacket)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

DataPacketDescriptor::~DataPacketDescriptor()
{
    delete[] propertyNames;
}

bool DataPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DataPacket *>(obj)!=nullptr;
}

const char **DataPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *DataPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int DataPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 18+base->getFieldCount() : 18;
}

unsigned int DataPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_srcNode
        FD_ISEDITABLE,    // FIELD_dstNode
        FD_ISEDITABLE,    // FIELD_ttl
        FD_ISEDITABLE,    // FIELD_lastRouter
        FD_ISEDITABLE,    // FIELD_l2
        FD_ISEDITABLE,    // FIELD_l3
        FD_ISEDITABLE,    // FIELD_l4
        FD_ISEDITABLE,    // FIELD_lastQueue
        FD_ISEDITABLE,    // FIELD_q2
        FD_ISEDITABLE,    // FIELD_q3
        FD_ISEDITABLE,    // FIELD_q4
        FD_ISEDITABLE,    // FIELD_q5
        FD_ISEDITABLE,    // FIELD_lastTS
        FD_ISEDITABLE,    // FIELD_t2
        FD_ISEDITABLE,    // FIELD_t3
        FD_ISEDITABLE,    // FIELD_t4
        FD_ISEDITABLE,    // FIELD_t5
        FD_ISEDITABLE,    // FIELD_routing
    };
    return (field >= 0 && field < 18) ? fieldTypeFlags[field] : 0;
}

const char *DataPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcNode",
        "dstNode",
        "ttl",
        "lastRouter",
        "l2",
        "l3",
        "l4",
        "lastQueue",
        "q2",
        "q3",
        "q4",
        "q5",
        "lastTS",
        "t2",
        "t3",
        "t4",
        "t5",
        "routing",
    };
    return (field >= 0 && field < 18) ? fieldNames[field] : nullptr;
}

int DataPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "srcNode") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "dstNode") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "ttl") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "lastRouter") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "l2") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "l3") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "l4") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "lastQueue") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "q2") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "q3") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "q4") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "q5") == 0) return baseIndex + 11;
    if (strcmp(fieldName, "lastTS") == 0) return baseIndex + 12;
    if (strcmp(fieldName, "t2") == 0) return baseIndex + 13;
    if (strcmp(fieldName, "t3") == 0) return baseIndex + 14;
    if (strcmp(fieldName, "t4") == 0) return baseIndex + 15;
    if (strcmp(fieldName, "t5") == 0) return baseIndex + 16;
    if (strcmp(fieldName, "routing") == 0) return baseIndex + 17;
    return base ? base->findField(fieldName) : -1;
}

const char *DataPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_srcNode
        "int",    // FIELD_dstNode
        "int",    // FIELD_ttl
        "int",    // FIELD_lastRouter
        "int",    // FIELD_l2
        "int",    // FIELD_l3
        "int",    // FIELD_l4
        "int",    // FIELD_lastQueue
        "int",    // FIELD_q2
        "int",    // FIELD_q3
        "int",    // FIELD_q4
        "int",    // FIELD_q5
        "double",    // FIELD_lastTS
        "double",    // FIELD_t2
        "double",    // FIELD_t3
        "double",    // FIELD_t4
        "double",    // FIELD_t5
        "int",    // FIELD_routing
    };
    return (field >= 0 && field < 18) ? fieldTypeStrings[field] : nullptr;
}

const char **DataPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *DataPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int DataPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void DataPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'DataPacket'", field);
    }
}

const char *DataPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DataPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        case FIELD_srcNode: return long2string(pp->getSrcNode());
        case FIELD_dstNode: return long2string(pp->getDstNode());
        case FIELD_ttl: return long2string(pp->getTtl());
        case FIELD_lastRouter: return long2string(pp->getLastRouter());
        case FIELD_l2: return long2string(pp->getL2());
        case FIELD_l3: return long2string(pp->getL3());
        case FIELD_l4: return long2string(pp->getL4());
        case FIELD_lastQueue: return long2string(pp->getLastQueue());
        case FIELD_q2: return long2string(pp->getQ2());
        case FIELD_q3: return long2string(pp->getQ3());
        case FIELD_q4: return long2string(pp->getQ4());
        case FIELD_q5: return long2string(pp->getQ5());
        case FIELD_lastTS: return double2string(pp->getLastTS());
        case FIELD_t2: return double2string(pp->getT2());
        case FIELD_t3: return double2string(pp->getT3());
        case FIELD_t4: return double2string(pp->getT4());
        case FIELD_t5: return double2string(pp->getT5());
        case FIELD_routing: return long2string(pp->getRouting());
        default: return "";
    }
}

void DataPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        case FIELD_srcNode: pp->setSrcNode(string2long(value)); break;
        case FIELD_dstNode: pp->setDstNode(string2long(value)); break;
        case FIELD_ttl: pp->setTtl(string2long(value)); break;
        case FIELD_lastRouter: pp->setLastRouter(string2long(value)); break;
        case FIELD_l2: pp->setL2(string2long(value)); break;
        case FIELD_l3: pp->setL3(string2long(value)); break;
        case FIELD_l4: pp->setL4(string2long(value)); break;
        case FIELD_lastQueue: pp->setLastQueue(string2long(value)); break;
        case FIELD_q2: pp->setQ2(string2long(value)); break;
        case FIELD_q3: pp->setQ3(string2long(value)); break;
        case FIELD_q4: pp->setQ4(string2long(value)); break;
        case FIELD_q5: pp->setQ5(string2long(value)); break;
        case FIELD_lastTS: pp->setLastTS(string2double(value)); break;
        case FIELD_t2: pp->setT2(string2double(value)); break;
        case FIELD_t3: pp->setT3(string2double(value)); break;
        case FIELD_t4: pp->setT4(string2double(value)); break;
        case FIELD_t5: pp->setT5(string2double(value)); break;
        case FIELD_routing: pp->setRouting(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DataPacket'", field);
    }
}

omnetpp::cValue DataPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        case FIELD_srcNode: return pp->getSrcNode();
        case FIELD_dstNode: return pp->getDstNode();
        case FIELD_ttl: return pp->getTtl();
        case FIELD_lastRouter: return pp->getLastRouter();
        case FIELD_l2: return pp->getL2();
        case FIELD_l3: return pp->getL3();
        case FIELD_l4: return pp->getL4();
        case FIELD_lastQueue: return pp->getLastQueue();
        case FIELD_q2: return pp->getQ2();
        case FIELD_q3: return pp->getQ3();
        case FIELD_q4: return pp->getQ4();
        case FIELD_q5: return pp->getQ5();
        case FIELD_lastTS: return pp->getLastTS();
        case FIELD_t2: return pp->getT2();
        case FIELD_t3: return pp->getT3();
        case FIELD_t4: return pp->getT4();
        case FIELD_t5: return pp->getT5();
        case FIELD_routing: return pp->getRouting();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'DataPacket' as cValue -- field index out of range?", field);
    }
}

void DataPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        case FIELD_srcNode: pp->setSrcNode(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_dstNode: pp->setDstNode(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_ttl: pp->setTtl(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_lastRouter: pp->setLastRouter(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_l2: pp->setL2(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_l3: pp->setL3(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_l4: pp->setL4(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_lastQueue: pp->setLastQueue(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_q2: pp->setQ2(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_q3: pp->setQ3(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_q4: pp->setQ4(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_q5: pp->setQ5(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_lastTS: pp->setLastTS(value.doubleValue()); break;
        case FIELD_t2: pp->setT2(value.doubleValue()); break;
        case FIELD_t3: pp->setT3(value.doubleValue()); break;
        case FIELD_t4: pp->setT4(value.doubleValue()); break;
        case FIELD_t5: pp->setT5(value.doubleValue()); break;
        case FIELD_routing: pp->setRouting(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DataPacket'", field);
    }
}

const char *DataPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr DataPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void DataPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DataPacket'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

