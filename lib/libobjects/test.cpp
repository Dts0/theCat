#include<iostream>
#include<stdlib.h>
#include<memory>
#include"./include/person.h"
#include<list>

list<RecObject*> *bufRecObjectList;
using namespace std;
int main(){
    bufRecObjectList=new list<RecObject*>;
    Object* object=new Object();
    cout<<object->getName()<<endl;
    IntelligentObject* i=new IntelligentObject();
    bufRecObjectList->push_front(i);
    cout<<i->getName()<<endl;
    Animal* a=new Animal();
    bufRecObjectList->push_front(a);
    cout<<a->getName()<<endl;
    Person* p=new Person();
    bufRecObjectList->push_front((Animal*)p);
    bufRecObjectList->push_front((IntelligentObject*)p);
    cout<<p->getName()<<endl;

    cout<<(*bufRecObjectList->begin())->getName()<<endl;
    bufRecObjectList->pop_front();
    cout<<(*bufRecObjectList->begin())->getName()<<endl;

    //****test for AI
    AI* ai=new AI("ai");
    ai->setIntroduce("AI introduce");
    cout<<ai->getName()<<ai->getId()<<endl;
    cout<<ai->getIntroduce()<<endl;

    bufRecObjectList->clear();
    delete object;
    delete i;
    delete a;
    delete p;
    delete ai;
    delete bufRecObjectList;
	return 0;
}



