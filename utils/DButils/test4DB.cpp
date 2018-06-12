#include<iostream>
#include<stdlib.h>
#include "database.h"
using namespace std;
int main(){
	DB_init();
	DB_exec("create table test(id integer primary key,name text);\
	insert into test values(1,'name1');\
	insert into test values(2,'name2');");

	DB_displayTable("test");
	return 0;
}
