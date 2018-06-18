g++ test4reply.c++ -g -Wall -O0 -I../../include/ -L.. -lreply -lskill -Wl,--rpath=.. -o test.out
./test.out 你好
rm -rf test.out
