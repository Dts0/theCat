#include<iostream>
#include<stdlib.h>
#include<string>
#include"reply.h"
#include"skill.h"
#include"play.h"
#include"record.h"
#include"voice2word.h"
#include"word2voice.h"

using namespace std;

int main(int argc,char* argv[]){
	replyInit();
	skillInit();

	string inputFile = "./buf/buf.pcm";
	string outputFile = "./buf/result.mp3";
	cout<<"inputFile:"<<inputFile<<endl;
	cout<<"outputFile:"<<outputFile<<endl;

	int time=5;
	start:
	cout<<"输入录音时间"<<endl;
	try{
	cin>>time;
	}catch(exception e){
		cout<<"请输入数字"<<endl;
		goto start;
	}
	string input = listen(time,inputFile);
	string output = reply(input);
	cout<<"回复:"<<output<<endl;
	say(output,outputFile);

	goto start;

	return 0;
}
