#include<iostream>
#include<stdlib.h>
#include"skill.h"
using namespace std;


const int MaxSkillId=10000;//extern
bool noInput_judgeFunc(std::string cmd);
std::string noInput_execFunc(int numP=0,list<long> pList=list<long>());
bool undefined_judgeFunc(std::string cmd);
std::string undefined_execFunc(int numP=0,list<long> pList=list<long>());
bool hello_judgeFunc(std::string cmd);
std::string hello_execFunc(int numP=0,list<long> pList=list<long>());
void replyInit(){
	skillInit();

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
}


bool inline rule_include(string inputStr,string str){//判断str是否为inputStr的字串
	return inputStr.find(str)!=string::npos;
}
bool inline rule_include_inOrder(string inputStr,string str0,string str1){//判断是否满足str0和str1都是inputStr的字串且str0在str1之前
	return inputStr.find(str0)!=string::npos && inputStr.find(str1)!=string::npos
                && inputStr.find(str0)<inputStr.find(str1);
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
	return "你好\n";
}


int main(){
	replyInit();
	DB_showSkills();
	return 0;
}
