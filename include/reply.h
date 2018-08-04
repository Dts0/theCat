#ifndef REPLY_H
#define REPLY_H

#include<string>
#include<stdlib.h>
#include"skill.h"

using namespace std;

bool inline rule_include(string inputStr,string str);
bool inline rule_include_inOrder(string inputStr,string str0,string str1);

string ask(string question,int waitTime=5,
				string inputFile="./buf/buf.pcm",string outputFile="./buf/result.mp3");//询问并直接获得结果
string listen(int waitTime=5,string inputFile="./buf/buf.pcm");
void say(string str,string outputFile="./buf/result.mp3");

void replyInit();//add the basic skills to SKILL moudle
string reply(string inputStr);
//string reply(char* inputStr);

#endif
