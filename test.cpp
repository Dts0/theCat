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

	start:
	int time=5;
	cout<<"输入录音时间"<<endl;
	cin>>time;

	system(("touch "+inputFile).c_str());//创建缓存文件
	system(("touch "+outputFile).c_str());

	cout<<"录音"<<time<<"秒"<<endl;
	record(time,inputFile);//录音
	cout<<"正在转语音..."<<endl;
	string input=voice2word(inputFile);//转语音
	cout<<"您的输入是:"<<input<<endl;
	string output = reply(input);
	cout<<"回复:"<<output<<endl;
	word2voice(output,outputFile);
	cout<<"正在将回复转换成语音..."<<endl;
	play(outputFile);
	cout<<"本轮回复结束"<<endl;

	goto start;

	return 0;
}
