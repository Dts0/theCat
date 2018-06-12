#include<iostream>
#include<stdlib.h>
#include<stdarg.h>
#include"../type.h"
using namespace std;
bool show(string cmd){
	cout<<"show it \n";
	cout<<cmd<<endl;
	return true;
}
string exec(int numP,...){
	va_list var_arg;
	va_start(var_arg,numP);
	for(int i=0;i<numP;i++){
		cout<<va_arg(var_arg,int);
	}
	cout<<endl;
	va_end(var_arg);
	return "finished";
}
int main(){
	std::map<std::string,skill> skills;
	skill s={
		.judgeFunc=show,
		.execFunc=exec,
		.introduce="介绍",
		.reply_success="成功",
		.reply_faith="失败"
	};

	//s.judgeFunc=show;
	s.judgeFunc("cmdd2");
	s.execFunc(3,1,2,3);
	skills.insert(pair<string,skill>("test",s));

	map<string, skill>::iterator iter;
	iter=skills.find("test");

	cout<<iter->second.introduce<<endl;
	cout<<iter->second.reply_success<<endl;
	cout<<"passed";
	return 0;
}
