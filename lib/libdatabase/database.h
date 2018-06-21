#ifndef DATABASE_H
#define DATABASE_H

#include <string>

typedef int callbackFunc(void* para,int columnCount,char** columnValue,char** columnName);

void DB_init(std::string filename = "/home/dts/桌面/theCat/database/database.db");
void DB_build(std::string build_filename = "/home/dts/桌面/theCat/database/build.sql");
bool DB_exec(std::string cmd,callbackFunc _callback = NULL);

void DB_displayTable(std::string tableName);
void DB_showRelations();
void DB_insertTestValues(std::string cmdString,std::string intent);

void DB_addHistroy(std::string cmd,std::string time);
void DB_showHistroys();

int display_callback(void* para,int columnCount,char** columnValue,char** columnName);
#endif // !DATABASE_H
