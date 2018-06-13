
#安装数据库sqlite
apt-get install sqlite sqlite3
apt-get install libsqlite3-dev
#创建数据库
(cd database;
 sqlite3 database.db .database .exit  
)
