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
bool display_judgeFunc(std::string cmd);
std::string display_execFunc(int numP=0,std::list<long> pList=std::list<long>());
bool display_skill_judgeFunc(std::string cmd);
std::string display_skill_execFunc(int numP=0,std::list<long> pList=std::list<long>());



int main(int argc,char* argv[]){
	replyInit();

	skill_t skill_tmp;
	skill_tmp.name="display histroy";
	skill_tmp.judgeFunc=display_judgeFunc;
	skill_tmp.execFunc=display_execFunc;
	skill_tmp.introduce="展示历史记录";
	skill_tmp.numP=0;
	skill_tmp.pList=list<long>();
	loadSkill(skill_tmp);

	skill_tmp.name="display skill";
	skill_tmp.judgeFunc=display_skill_judgeFunc;
	skill_tmp.execFunc=display_skill_execFunc;
	skill_tmp.introduce="展示技能列表";
	skill_tmp.numP=0;
	skill_tmp.pList=list<long>();
	loadSkill(skill_tmp);

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


bool display_judgeFunc(std::string cmd){
	return rule_include(cmd,"历史记录");
}
std::string display_execFunc(int numP,std::list<long> pList){
	DB_showHistroys();
	return "好的，已展示历史记录";
}
bool display_skill_judgeFunc(std::string cmd){
	return rule_include(cmd,"你")&&(rule_include(cmd,"能")||rule_include(cmd,"会"))&&rule_include(cmd,"什么");
}
std::string display_skill_execFunc(int numP,std::list<long> pList){
	DB_showSkills();
	return "好的，这是我能做的事情";
}
