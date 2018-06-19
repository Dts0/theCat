SRCS    = $(wildcard *.cpp)
OBJS    = $(patsubst %.cpp, %.o, $(SRCS))

CC      = g++
CFLAGS  = -g -Wall -O0

TARGET      = ../libgbk_utf8.a
INC_PATH    = -I..
LIB_PATH    = -L..

EXT_LIB     = #../lib/libreply.a
EXT_SO		= #-L. -lreply -Wl,--rpath=./lib/
EXT_SO_CC	= #-fPIC

all:$(TARGET)

$(TARGET):$(OBJS)
	ar crv $@ $^
#$(CC) $(LIB_PATH) $(CFLAGS) -o $@ $^ $(EXT_LIB) $(EXT_SO) 

%.o:%.cpp
	$(CC) $(INC_PATH) $(CFLAGS) -c -o $@ $<
%.o:%.c
	$(CC) $(INC_PATH) $(CFLAGS) -c -o $@ $<

run:$(TARGET)
	$(TARGET)

clear:	#只删除中间文件的命令
	rm -rf $(OBJS)
	
.PHONY:clean
clean:
	rm -rf $(TARGET) $(OBJS)

test:
	make
	g++ test.c++ -L.. -lgbk_utf8 -o test.out
	./test.out
	rm -rf test.out
	rm -rf *.o

