#include <iostream>
#include <string>
#include "stdlib.h"
#include "reply.h"
#include"play.h"
#include"record.h"
#include"voice2word.h"
#include"word2voice.h"
#include "weather.h"

using namespace std;


string selfName="凯特猫";
string masterName="梦";


bool inline rule_include(string inputStr,string str){//判断str是否为inputStr的字串
	return inputStr.find(str)!=string::npos;
}
bool inline rule_include_inOrder(string inputStr,string str0,string str1){//判断是否满足str0和str1都是inputStr的字串且str0在str1之前
	return inputStr.find(str0)!=string::npos && inputStr.find(str1)!=string::npos
                && inputStr.find(str0)<inputStr.find(str1);
}


string ask(string question,int waitTime,
				string inputFile,string outputFile){
					say(question,outputFile);
					return listen(waitTime,inputFile);
				}

string listen(int waitTime,string inputFile){
	system(("touch "+inputFile).c_str());//创建缓存文件

	cout<<"录音"<<waitTime<<"秒"<<endl;
	record(waitTime,inputFile);//录音
	cout<<"正在转语音..."<<endl;
	string input=voice2word(inputFile);//转语音
	cout<<"您的输入是:"<<input<<endl;
	return input;
}

void say(string str,string outputFile){
	system(("touch "+outputFile).c_str());

	word2voice(str,outputFile);
	cout<<"正在将回复转换成语音..."<<endl;
	play(outputFile);
	cout<<"本轮回复结束"<<endl;
}

string reply(string inputStr){
	string r="";

	map<int,skill_t>::iterator iter;
	for(iter=skills.begin();iter!=skills.end();iter++){
		if(iter->second.judgeFunc==NULL)
			continue;
		if(iter->second.judgeFunc(inputStr)){
			if(iter->second.execFunc==NULL){
				r="执行失败,技能"+iter->second.name+"没有执行函数";
				goto reply_end;
			} else ;
			r=iter->second.execFunc(iter->second.numP,iter->second.pList);
			goto reply_end;

		}
	}

	reply_end:
    return r;

}

extern "C" {
char* c_reply(char* inputStr){//the C type API
	if(inputStr==NULL)
		return "需要输入\n";
	else
     	return (char*)reply(string(inputStr)).c_str();

 }
}

int _skillId;//extern
const int MaxSkillId=10000;//extern
bool noInput_judgeFunc(std::string cmd);
std::string noInput_execFunc(int numP=0,list<long> pList=list<long>());
bool undefined_judgeFunc(std::string cmd);
std::string undefined_execFunc(int numP=0,list<long> pList=list<long>());
bool hello_judgeFunc(std::string cmd);
std::string hello_execFunc(int numP=0,list<long> pList=list<long>());
bool exit_judgeFunc(std::string cmd);
std::string exit_execFunc(int numP=0,list<long> pList=list<long>());
void replyInit(){
	skill_t tmp;
	tmp.name="noInput";
	tmp.judgeFunc=noInput_judgeFunc;
	tmp.execFunc=noInput_execFunc;
	tmp.introduce="没有输入时的回复";
	tmp.numP=0;
	tmp.pList=list<long>();
	loadSkill(tmp);

	tmp.name="undefined";
	tmp.judgeFunc=undefined_judgeFunc;
	tmp.execFunc=undefined_execFunc;
	tmp.introduce="未定义的命令";
	tmp.numP=0;
	tmp.pList=list<long>();
	loadSkill(tmp,MaxSkillId);//最后一个判断的命令，如果该命令执行，说明所有的都已经不符合条件

	tmp.name="hello";
	tmp.judgeFunc=hello_judgeFunc;
	tmp.execFunc=hello_execFunc;
	tmp.introduce="问好";
	tmp.numP=0;
	tmp.pList=list<long>();
	loadSkill(tmp);

	tmp.name="exit";
	tmp.judgeFunc=exit_judgeFunc;
	tmp.execFunc=exit_execFunc;
	tmp.introduce="退出";
	tmp.numP=0;
	tmp.pList=list<long>();
	loadSkill(tmp);

	tmp.name="weather";
	tmp.judgeFunc=weather_judgeFunc;
	tmp.execFunc=weather_execFunc;
	tmp.introduce="查天气";
	tmp.numP=0;
	tmp.pList=list<long>();
	loadSkill(tmp);
}
//接下来是对skill的各个函数定义
bool noInput_judgeFunc(std::string cmd){
	return cmd.empty();
}
std::string noInput_execFunc(int numP,list<long> pList){
	return "您没有输入命令。如果您说出了命令，请检查联网和麦克风的连接情况\n";
}
bool undefined_judgeFunc(std::string cmd){
	return true;
}
std::string undefined_execFunc(int numP,list<long> pList){
	return "您输入了未定义的命令\n";
}
bool hello_judgeFunc(std::string cmd){
	return rule_include(cmd,"你好");
}
std::string hello_execFunc(int numP,list<long> pList){
	return "你好，"+masterName+"\n";
}
bool exit_judgeFunc(std::string cmd){
	return (rule_include(cmd,"退出")||rule_include(cmd,"关闭"));
}
std::string exit_execFunc(int numP,list<long> pList){
	say("好的，正在退出本程序");
	exit(0);
	return "退出";
}
