#ifndef PERSON_H
#define PERSON_H

#include"IntelligentObject.h"

class Person:public Animal,public IntelligentObject {
protected:
	uuid_t id;
	string name;
public:
	Person(string n="Person",Sex s=unknown);
	~Person();
	string toString() const;
	string getId() const;
	string getName() const;
	void setName(string n);
};

#endif
