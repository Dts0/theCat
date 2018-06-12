#ifndef DATABASE_H
#define DATABASE_H

#include <string>

typedef int callbackFunc(void* para,int columnCount,char** columnValue,char** columnName);

void DB_init(std::string filename = "database.db");
bool DB_exec(std::string cmd,callbackFunc _callback = NULL);
void DB_displayTable(std::string tableName);

#endif // !DATABASE_H
