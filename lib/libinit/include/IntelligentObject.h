#ifndef INTELLIGENT_OBJECT_H
#define INTELLIGENT_OBJECT_H

#include"object.h"

typedef struct Mood{//心情
	unsigned char happy;//sad,兴奋程度
	unsigned char angry;//生气程度
	unsigned char afraid;//恐惧程度
	unsigned char bored;//无聊程度
	unsigned char disappointed;//失望程度
	unsigned char awkward;//尴尬程度
} Mood;
class IntelligentObject:public RecObject{
protected:
	Mood mood;
    bool busy;
public:
	IntelligentObject(string n="IntelligentObject");
	~IntelligentObject();
	Mood getMood() const;
	void setMood(Mood m);
    bool isBusy() const;
    void setBusy(bool b);

    //
    void talk(IntelligentObject target,int language);
};

class AI:public IntelligentObject{
protected:
    IntelligentObject* master;
public:
    AI(string n="AI");
    ~AI();
    IntelligentObject* getMaster() const;
};

class Self:public AI{
public:
    Self(string n="Cat");
    ~Self();
};

#endif
