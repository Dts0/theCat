SRCS    = $(wildcard *.cpp)
OBJS    = $(patsubst %.cpp, %.o, $(SRCS))

CC      = g++
CFLAGS  = -g -Wall -O0

TARGET      = ./bin/test.out
INC_PATH    = -I$(TOP_DIR)./include/
LIB_PATH    = -L$(TOP_DIR)./lib/

EXT_LIB     = #./lib/libreply.a					#如果需要使用静态库时修改的参数
EXT_SO		= -L. -lreply -lskill -lplay_record -ldatabase -lsqlite3 -lvoice_word -lgbk_utf8 -lnetwork -ljson -Wl,--rpath=./lib/	#如果需要使用动态库时修改的参数

all:
	(make copy_h)
	(cd lib/libdatabase;make)
#	(cd lib/libobjects;make)
	(cd lib/libplay_record;make)
	(cd lib/libreply;make)
	(cd lib/libvoice_word;make)
	(cd lib/libskills;make)
	(cd lib/libnetwork;make)
	(cd lib/GBK2UTF-8;make)
	(cd lib/libjson;make)
	make $(TARGET)
	echo"make successfully!"

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
	(cd lib/libdatabase;make clear)
#	(cd lib/libobjects;make clear)
	(cd lib/libplay_record;make clear)
	(cd lib/libreply;make clear)
	(cd lib/libvoice_word;make clear)
	(cd lib/libskills;make clear)
	(cd lib/libnetwork;make clear)
	(cd lib/GBK2UTF-8;make clear)
	(cd lib/libjson;make clear)
	rm -rf $(OBJS)
	rm -rf ./buf/buf.pcm ./buf/result.mp3 ./buf/result.txt ./buf/reply.txt
	rm -rf ./buf/weather.json
	rm -rf ./database/*.sql ./database/*.db

.PHONY:clean
clean:
	(cd lib/libdatabase;make clean)
#	(cd lib/libobjects;make clean)
	(cd lib/libplay_record;make clean)
	(cd lib/libreply;make clean)
	(cd lib/libvoice_word;make clean)
	(cd lib/libskills;make clean)
	(cd lib/libnetwork;make clean)
	(cd lib/GBK2UTF-8;make clean)
	(cd lib/libjson;make clean)
	rm -rf $(TARGET) $(OBJS)
	rm -rf ./buf/buf.pcm ./buf/result.mp3 ./buf/result.txt ./buf/reply.txt
	rm -rf ./buf/weather.json
	rm -rf ./database/*.sql ./database/*.db

copy_h:
	rm -rf include/*.h
#	cp */*.h include
	cp */*/*.h include -n
	cp */*/*/*.h include -n
	./delNeedlessH.sh
	
	
	

