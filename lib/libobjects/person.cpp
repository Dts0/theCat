#include"include/person.h"
#include<iostream>
using namespace std;
Person::Person(string n,Sex s):Animal(n,s),IntelligentObject(n){}
Person::~Person(){}

string Person::toString() const{
    return IntelligentObject::toString();
}
string Person::getId() const{
    return IntelligentObject::getId();
}
string Person::getName() const{
    return IntelligentObject::getName();
}
void Person::setName(string n){
    IntelligentObject::setName(n);
    Animal::setName(n);
}
