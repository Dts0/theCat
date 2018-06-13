g++ test4DB.c++ database.cpp database_local.cpp  -lsqlite3
./a.out

rm a.out
rm $CAT_HOME/database/database.db

#the result should be 
#open sqlite database succeed
#OK,execed
#close sqlite database succeed
#open sqlite database succeed
#	id		name	
#	1		name1	
#	2		name2	
#OK,execed
#close sqlite database succeed

                    
