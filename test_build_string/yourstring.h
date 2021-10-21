#include <string.h>

template <class T>
class RCPtr{
public:
    RCPtr(T* realPtr = 0);
    RCPtr(const RCPtr& rhs);
    ~RCPtr();
    RCPtr& operator=(const RCPtr& rhs);
    T* operator->() const;
    T& operator*() const;

private:
    T* pointee;
    void init();
};

class RCObject{
public:
    void addReference();
    void removeReference();
    void markUnshareable();
    bool isShareable() const;
    bool isShared() const;

protected:
    RCObject();
    RCObject(const RCObject& rhs);
    RCObject& operator=(const RCObject& rhs);
    virtual ~RCObject() = 0;

private:
    int refCount;
    bool shareable;
};

class String{
public:
    String(const char* value = "");
    const char& operator[](int index) const;
    char & operator[] (int index);

private:
    struct StringValue : public RCObject
    {
        char * data;
        StringValue(const char* initValue);
        StringValue(const StringValue& rhs);
        void init(const char* initValue);
        ~StringValue();
    };
    RCPtr<StringValue> value;
    
};

RCObject::RCObject()
    :refCount(0), shareable(true) {}

RCObject::RCObject(const RCObject&)
    :refCount(0), shareable(true) {}

RCObject & RCObject::operator=(const RCObject& )
{
    return *this;
}

RCObject::~RCObject() {}

void RCObject::addReference() { ++refCount; }

void RCObject::removeReference()
{
    if (--refCount == 0)
        delete this;
}

void RCObject::markUnshareable()
{
    shareable = false;
}

bool RCObject::isShareable() const
{
    return shareable;
}

bool RCObject::isShared() const
{
    return refCount > 1;
}



template <class T>
void RCPtr<T>::init()
{
    if (pointee == 0)
        return;
    if (pointee->isShareable() == false)
    {
        pointee = new T(*pointee);
    }
    pointee->addReference();
}

template<class T>
RCPtr<T>::RCPtr(T* realPtr)
    :pointee(realPtr)
{
    init();
}

template<class T>
RCPtr<T>::RCPtr(const RCPtr& rhs)
    :pointee(rhs.pointee)
{
    init();
}

template<class T>
RCPtr<T>::~RCPtr()
{
    if (pointee)
        pointee->removeReference();
}

template<class T>
RCPtr<T> & RCPtr<T>::operator=(const RCPtr & rhs)
{
    if(pointee != rhs.pointee)
    {
        if(pointee)
            pointee->removeReference();
        pointee = rhs.pointee;
        init();
    }
    return *this;
}


template<class T>
T* RCPtr<T>::operator->() const 
{
    return pointee;
}

template<class T>
T& RCPtr<T>::operator*() const
{
    return *pointee;

}

void String::StringValue::init(const char* initValue)
{
    data = new char[strlen(initValue) + 1];
    strcpy(data, initValue);
}

String::StringValue::StringValue(const char* initValue)
{
    init(initValue);
}


String::StringValue::StringValue(const StringValue& rhs)
{
    init(rhs.data);
}

String::StringValue::~StringValue()
{
    delete [] data;
}


String::String(const char* initValue)
    :value(new StringValue(initValue))
{

}


const char& String::operator[] (int index) const
{
    return value->data[index];
}

char& String::operator[] (int index)
{
    if (value->isShared())
    {
        value = new StringValue(value->data);
    }
    value->markUnshareable();
    return value->data[index];
}







