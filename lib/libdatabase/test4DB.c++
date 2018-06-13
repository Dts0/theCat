#include<iostream>
#include<stdlib.h>
#include <string>
#include <sstream>
#include "database.h"
using namespace std;
int main(){
	DB_init();
	/*
	DB_exec("create table test(id integer primary key,name text);\
	insert into test values(1,'name1');\
	insert into test values(2,'name2');");

	DB_displayTable("test");
	*/
	DB_build();

	for(int i=0;i<100;i++)
		{
			ostringstream buf;
			buf<<i;
			DB_insertTestValues("cmd"+buf.str(),"intent"+buf.str());
		}
	DB_showRelations();
	return 0;
}
