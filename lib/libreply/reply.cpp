#include <iostream>
#include <string>
#include <list>
#include "include/reply.h"

using namespace std;


string selfName="cat";
string tagetName="master";
string strs_Negative[]={"不","否","没","非"};//否定词,应当放到init模块，外部只留list
list<string> list_Negative=new list<string>(strs_Negative,strs_Negative+3);


string randomStr(list<string> l){}//从list中随机取出一个
bool inStr(string inputStr,string str){//判断str是否为inputStr的字串
	return inputStr.find(str)!=string::npos;
}
bool inStrAndByOrder(string inputStr,string str0,string str1){//判断是否满足str0和str1都是inputStr的字串且str0在str1之前
	return inputStr.find(str0)!=string::npos && inputStr.find(str1)!=string::npos
                && inputStr.find(str0)<inputStr.find(str1);
}

string reply(string inputStr){
	string r="";
	if(inputStr.empty()){
        r="你说啥?我没听清\n";
        goto ReplyEnd;
	}
    if(inStr(inputStr,"你好")){
    	r="你好\n";
    	goto ReplyEnd;
    }
    if(inStrAndByOrder(inputStr,"你","名字")||inStrAndByOrder(inputStr,"你","叫什么")){
    	r="我叫"+selfName+"\n";
    	goto ReplyEnd;
    }

    r="未定义的指令\n";
    ReplyEnd:
    return r;

}

char* c_reply(char* inputStr){
	if(inputStr==NULL)
		return "需要输入\n";
	else
     	return (char*)reply(string(inputStr)).c_str();
    
 }

 
 
