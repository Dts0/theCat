CAT_HOME=/home/dts/桌面/theCat

SRCS    = $(wildcard *.cpp)
OBJS    = $(patsubst %.cpp, %.o, $(SRCS))

CC      = g++
CFLAGS  = -g -Wall -O0 $(EXT_SO_CC)

TARGET      = ../libnetwork.so
INC_PATH    = -I.
LIB_PATH    = -L..

EXT_LIB     = #../lib/libreply.a
EXT_SO		= -L. -Wl,--rpath=./lib/
EXT_SO_CC	= -fPIC	#编译动态库时需要额外添加的参数

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) -shared -fPIC -o $(TARGET) $(OBJS)
	(cd $(CAT_HOME)/buf/python;cp $(CAT_HOME)/lib/libnetwork/doGet.py .)

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
	rm -rf $(CAT_HOME)/buf/python/doGet.py
test:
	./test.sh

