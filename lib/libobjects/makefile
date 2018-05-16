SRCS    = $(wildcard *.cpp)
OBJS    = $(patsubst %.cpp, %.o, $(SRCS))

CC      = g++
CFLAGS  = -g -Wall -O0

TARGET      = ./bin/test.out
INC_PATH    = -I./include/
LIB_PATH    = -L./lib/

EXT_LIB     = #./lib/libreply.a					#如果需要使用静态库时修改的参数
EXT_SO		= -L. -lpthread -luuid -Wl,--rpath=./lib/	#如果需要使用动态库时修改的参数

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

clear:
	rm -rf $(OBJS)

.PHONY:clean
clean:
	rm -rf $(TARGET) $(OBJS)
