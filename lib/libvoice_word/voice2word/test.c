#include<iostream>
#include<stdlib.h>
#include"voice2word.h"
using namespace std;
int main(){
	system("arecord -d 5 -r16000 -f S16_LE -t wav -D \"plughw:1,0\" test.pcm");
	cout<<voice2word();
	return 0;
}

