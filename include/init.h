#ifndef INIT_H
#define INIT_H
#include<list>
#include"object.h"
#include"person.h"

extern list<SysObject*> *sysObjectList;
extern list<RecObject*> *bufRecObjectList;//常用的可被认知对象

void objectListInit(int bufSize);


#endif // INIT_H
