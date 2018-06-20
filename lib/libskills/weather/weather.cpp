#include "weather.h"
#include "GBK_UTF8.h"
#include "network.h"
#include "reply.h"
using namespace std;

bool weather_judgeFunc(std::string cmd){
	return rule_include(cmd,"天气");
}
std::string weather_execFunc(int numP,list<long> pList){
	string answer=ask("您想要查询哪里的天气?");
	//answer.pop_back();//删除最后一个多余的字符,对于百度识别为去掉，
	string city=UTF_82GBK_X(answer);
	doGet("v.juhe.cn/weather/index",
	"cityname="+city+"&dtype=xml&format=2&key=1218059ee4c3713769eed2335e8a77c6",
	"./buf/weather.xml",80);


	return "";
}
