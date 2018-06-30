#include<iostream>
#include<stdlib.h>
#include<string>
#include"reply.h"
#include"skill.h"
#include"play.h"
#include"record.h"
#include"voice2word.h"
#include"word2voice.h"
#include "database.h"
#include <time.h>

using namespace std;

int main(int argc,char* argv[]){
	replyInit();
	skillInit();
	DB_init();
	DB_build();

	string inputFile = "./buf/buf.pcm";
	string outputFile = "./buf/result.mp3";
	cout<<"inputFile:"<<inputFile<<endl;
	cout<<"outputFile:"<<outputFile<<endl;

	int waitTime=5;
	start:
	cout<<"输入录音时间"<<endl;
	cin>>waitTime;

	if(waitTime<=0){
		cout<<"已填入默认值5秒"<<endl;
		waitTime=5;
	}
	string input = listen(waitTime,inputFile);
	string output = reply(input);
	cout<<"回复:"<<output<<endl;
	say(output,outputFile);

	time_t timep;
    time(&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S",localtime(&timep) );
	string timeStr(tmp);
	cout<<timeStr<<endl;
	DB_addHistroy(input,timeStr);
	goto start;

	return 0;
}
