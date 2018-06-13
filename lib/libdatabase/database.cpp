#include <iostream>
#include <stdlib.h>
#include <sqlite3.h>
#include "database.h"

using namespace std;

char* database_errmsg;
const int maxLength = 50;
string DB_filename;
sqlite3 *db = NULL;
sqlite3_stmt *stmt = NULL;

bool inline _DB_open(){
	if (SQLITE_OK != sqlite3_open(DB_filename.c_str(), &db)) {
		cout<<"open sqlite database fail"<<sqlite3_errmsg(db)<<endl;
		return false;
    } else {
        //cout<<"open sqlite database succeed\n";
		return true;
    }
}

bool inline _DB_close(){
	if(SQLITE_OK != sqlite3_close(db)){
		cout<<"close sqlite database fail,"<<sqlite3_errmsg(db)<<endl;
		return false;
	} else {
		//cout<<"close sqlite database succeed\n";
		return true;
	}
}

void DB_init(string filename){
	sqlite3_os_init();
	DB_filename=filename;
	//system(("sqlite3 "+filename+" .database .exit").c_str());
}

bool DB_exec(std::string cmd,callbackFunc _callback){
	bool ret;
	_DB_open();
	int result = sqlite3_exec(db,cmd.c_str(),_callback,NULL,&database_errmsg);
	if(SQLITE_OK==result){
		//cout<<"OK,execed\n";
		ret=true;
	}
	else {
		cout<<"Error,the err code is "<<result<<",err message is "<<database_errmsg<<"\n";
		ret=false;
	}
	_DB_close();
	return ret;
}

int display_callback(void* para,int columnCount,char** columnValue,char** columnName){
	static int firstTime=1;
	if(firstTime){
		firstTime=0;
		for(int i=0;i<columnCount;i++)
			cout<<"\t"<<columnName[i]<<"\t";
		cout<<endl;
	}
	for(int i=0;i<columnCount;i++)
		cout<<"\t"<<columnValue[i]<<"\t";
	cout<<endl;
	return 0;
}

void DB_displayTable(std::string tableName){
	DB_exec("select * from "+tableName,display_callback);
}
