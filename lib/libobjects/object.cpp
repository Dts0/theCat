#include"./include/object.h"
#include"./include/objectlist.h"

using namespace std;
/***********Object***************/
Object::Object(string n){
    uuid_generate(id);
	if(n!="")
		name=n;
	if(n==""){
		char s[36+1];
        uuid_unparse(id, s);
        name=n.append("Object").append("_").append(s);
	}

}
Object::~Object(){}
string Object::toString() const{
	return name;
}
string Object::getId() const{
	char s[36+1];
	uuid_unparse(id, s);
	return string(s);
}
string Object::getName() const{
	return name;
}
void Object::setName(string n){
	name=n;
}
/*************ObjectEnd*****************/

/*************SysObject*****************/
SysObject::SysObject(string n):Object(n){}
SysObject::~SysObject(){}
/*************SysObjectEnd**************/

/*************RecObject*****************/
RecObject::RecObject(string n):Object(n){
    introduce=string("");
}
RecObject::~RecObject(){}
string RecObject::getIntroduce() const{
    return introduce;
}
void RecObject::setIntroduce(string i){
    introduce=i;
}
/*************RecObjectEnd**************/

/*************Creature******************/
Biology::Biology(string n):RecObject(n){
    alive=true;
}
Biology::~Biology(){}
bool Biology::isAlive() const{
	return alive;
}
void Biology::setAlive(bool a){
	alive=a;
}
/*************CreatureEnd***************/

/*************Animal********************/
Animal::Animal(string n,Sex s):Biology(n){
	sex=s;
}
Animal::~Animal(){}
Sex Animal::getSex() const{
    return sex;
}
void Animal::setSex(Sex s){
    sex=s;
}
/*************AnimalEnd*****************/
























