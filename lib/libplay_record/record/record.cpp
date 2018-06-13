#include <stdlib.h>
#include <stdio.h>
#include "record.h"

void record(int time,std::string filepath){
	char buf[100];
	sprintf(buf,"arecord -d %d -r16000 -f S16_LE -t wav -D \"plughw:1,0\" %s",time,filepath.c_str());
    system(buf);
}

