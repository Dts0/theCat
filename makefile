SRCS    = $(wildcard *.cpp)
OBJS    = $(patsubst %.cpp, %.o, $(SRCS))

CC      = g++
CFLAGS  = -g -Wall -O0

TARGET      = ./bin/test.out
INC_PATH    = -I$(TOP_DIR)./include/
LIB_PATH    = -L$(TOP_DIR)./lib/

EXT_LIB     = #./lib/libreply.a					#如果需要使用静态库时修改的参数
EXT_SO		= -L. -lreply -lskill -lplay_record -ldatabase -lvoice_word -Wl,--rpath=./lib/	#如果需要使用动态库时修改的参数

all:
	(make copy_h)
	(cd lib/libdatabase;make)
	(cd lib/lib4test;make)
#	(cd lib/libobjects;make)
	(cd lib/libplay_record;make)
	(cd lib/libreply;make)
	(cd lib/libvoice_word;make)
	(cd lib/libskills;make)
	make $(TARGET)

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
	(cd lib/lib4test;make clear)
#	(cd lib/libobjects;make clear)
	(cd lib/libplay_record;make clear)
	(cd lib/libreply;make clear)
	(cd lib/libvoice_word;make clear)
	(cd lib/libskills;make clear)
	rm -rf $(OBJS)

.PHONY:clean
clean:
	(cd lib/libdatabase;make clean)
	(cd lib/lib4test;make clean)
	(cd lib/libobjects;make clean)
	(cd lib/libplay_record;make clean)
	(cd lib/libreply;make clean)
	(cd lib/libvoice_word;make clean)
	(cd lib/libskills;make clean)
	rm -rf $(TARGET) $(OBJS)
copy_h:
	rm -rf include/*.h
	#cp */*.h include
	cp */*/*.h include -n
	cp */*/*/*.h include -n
