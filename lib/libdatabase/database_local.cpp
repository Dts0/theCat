#include "database.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
void DB_build(std::string build_filename){
	ifstream in(build_filename.c_str());
	ostringstream tmp;
	tmp << in.rdbuf();
	DB_exec(tmp.str());
}
void DB_showRelations(){
	string cmd="select relation.id,relation.intent,command.cmdString from command,relation where command.id=relation.command;";
	DB_exec(cmd,display_callback);
}
void DB_insertTestValues(std::string cmdString,std::string intent){
	string cmd="insert into command(cmdString) values('"+cmdString+"');"
	+"insert into relation(intent,command) values('"+intent
	+"',(select id from command where cmdString='"+cmdString+"'));";
	DB_exec(cmd);
}
