#include"include/IntelligentObject.h"
using namespace std;

IntelligentObject::IntelligentObject(string n):RecObject(n){}
IntelligentObject::~IntelligentObject(){}
Mood IntelligentObject::getMood() const{
	return mood;
}
void IntelligentObject::setMood(Mood m){
	mood=m;
}
bool IntelligentObject::isBusy() const{
    return busy;
}
void IntelligentObject::setBusy(bool b){
    busy=b;
}


AI::AI(string n):IntelligentObject(n){
    busy=false;
}
AI::~AI(){}
IntelligentObject *AI::getMaster() const{
    return master;
}


Self::Self(string n):AI(n){}
Self::~Self(){}
