SRCS    = $(wildcard *.cpp)
OBJS    = $(patsubst %.cpp, %.o, $(SRCS))

CC      = g++
CFLAGS  = -g -Wall -O0 $(EXT_SO_CC)

TARGET      = ./bin/test.out
INC_PATH    = -I./include/
LIB_PATH    = -L..

EXT_LIB     = #./lib/libreply.a
EXT_SO		= -L. -lobjects -Wl,--rpath=./lib/
EXT_SO_CC	= -fPIC

all:$(TARGET)

$(TARGET):$(OBJS)
	if [ ! -d "bin/" ];then mkdir bin;fi
	$(CC) $(LIB_PATH) $(CFLAGS) -o $@ $^ $(EXT_LIB) $(EXT_SO) 

%.o:%.cpp
	$(CC) $(INC_PATH) $(CFLAGS) -c -o $@ $<
%.o:%.c
	$(CC) $(INC_PATH) $(CFLAGS) -c -o $@ $<

run:$(TARGET)
	$(TARGET)

.PHONY:clean
clean:
	rm -rf $(TARGET) $(OBJS)
