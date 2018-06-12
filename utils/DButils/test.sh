g++ test4DB.cpp database.cpp -lsqlite3
./a.out

rm a.out
rm database.db

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

                    
