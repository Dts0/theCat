#ifndef OBJECT_H
#define OBJECT_H

#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<uuid/uuid.h>

using namespace std;

class Object{
protected://如果保密要求高,这部分应当替换为一个指向private的指针
	uuid_t id;
	string name;
public:
	Object(string n="Object");
	virtual ~Object();//虚析构函数以调用子类的析构函数
	string toString() const;
	string getId() const;
	string getName() const;
	void setName(string n);
};

class SysObject:public Object{//不应当被外界直接调用或不应被Cat自身认知到的对象
public:
	SysObject(string n="SysObject");
	~SysObject();
};

class RecObject:public Object{
protected:
    string introduce;
public:
	RecObject(string n="RecObject");
	~RecObject();
    string getIntroduce() const;
    void setIntroduce(string i);
};

class Biology:public RecObject{
protected:
	bool alive;
public:
	Biology(string n="Biology");
	~Biology();
	bool isAlive() const;
	void setAlive(bool a);
};

enum Sex{male,female,unknown};
class Animal:public Biology{
protected:
	Sex sex;
public:
	Animal(string n="Animal",Sex s=unknown);
	~Animal();
    Sex getSex() const;
    void setSex(Sex s);
};
#endif
