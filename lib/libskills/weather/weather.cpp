#include "weather.h"
#include "GBK_UTF8.h"
#include "network.h"
#include "reply.h"
#include <stdlib.h>
#include <json/json.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

string readFileJson();
bool weather_judgeFunc(std::string cmd){
	return rule_include(cmd,"天气");
}
std::string weather_execFunc(int numP,list<long> pList){
	string answer="";
	answer=ask("您想要查询哪里的天气?",3);

	answer.resize(answer.size()-4);
	string city=GBK2UTF_8_X(UTF_82GBK(answer));
	cout<<"正在查询"<<answer<<"的天气..."<<endl;

	//cout<<city<<endl<<"cityname="+city+"&dtype=&format=&key=1218059ee4c3713769eed2335e8a77c6"<<endl;
	doGet("v.juhe.cn/weather/index",
	"cityname="+city+"&dtype=&format=&key=1218059ee4c3713769eed2335e8a77c6",
	"./buf/weather.json",80);

	return readFileJson();
}

//从文件中读取JSON
string readFileJson()
{
    Json::Reader reader;
    Json::Value root;

    //从文件中读取，保证当前文件有test.json文件
    ifstream in("./buf/weather.json", ios::binary);
    //in.open("test.json", ios::binary);

    if( !in.is_open() )
    {
    return "无法连接到天气服务器，请检查网络连接。";
    }

    if(reader.parse(in,root))
    {
    //读取根节点信息
    int error_code = root["error_code"].asInt();
	if(error_code!=0){
		return "查询失败。";
	}
	}
	stringstream ret;
	string city = root["result"]["today"]["city"].asString();
	string temp = root["result"]["sk"]["temp"].asString();
	string wind_direction = root["result"]["sk"]["wind_direction"].asString();
	string wind_strength = root["result"]["sk"]["wind_strength"].asString();
	ret<<city<<"当前温度"<<temp<<"摄氏度，"<<wind_direction<<wind_strength<<"。";

	string weather = root["result"]["today"]["weather"].asString();
	string temperature = root["result"]["today"]["temperature"].asString();
	string wind = root["result"]["today"]["wind"].asString();
	string dressing_advice = root["result"]["today"]["dressing_advice"].asString();
	ret<<"今天天气"<<weather<<"，"<<temperature<<"，"<<wind<<"，"<<dressing_advice<<"。";
    in.close();

	return ret.str();
}
/*json格式
{
	"resultcode":"200",
	"reason":"successed!",
	"result":{
		"sk":{
			"temp":"23",
			"wind_direction":"南风",
			"wind_strength":"4级",
			"humidity":"76%",
			"time":"15:11"
		},
		"today":{
			"temperature":"20℃~28℃",
			"weather":"晴",
			"weather_id":{
				"fa":"00",
				"fb":"00"
			},
			"wind":"北风3-5级",
			"week":"星期三",
			"city":"青岛",
			"date_y":"2018年06月20日",
			"dressing_index":"热",
			"dressing_advice":"天气热，建议着短裙、短裤、短薄外套、T恤等夏季服装。",
			"uv_index":"强",
			"comfort_index":"",
			"wash_index":"较适宜",
			"travel_index":"较适宜",
			"exercise_index":"较适宜",
			"drying_index":""
		},
		"future":{
			"day_20180620":{
				"temperature":"20℃~28℃",
				"weather":"晴",
				"weather_id":{
					"fa":"00",
					"fb":"00"
				},
				"wind":"北风3-5级",
				"week":"星期三",
				"date":"20180620"
			},
			"day_20180621":{
				"temperature":"22℃~27℃",
				"weather":"晴转多云",
				"weather_id":{
					"fa":"00",
					"fb":"01"
				},
				"wind":"南风3-5级",
				"week":"星期四",
				"date":"20180621"
			},
			"day_20180622":{
				"temperature":"20℃~28℃",
				"weather":"多云转晴",
				"weather_id":{
					"fa":"01",
					"fb":"00"
				},
				"wind":"南风3-5级",
				"week":"星期五",
				"date":"20180622"
			},
			"day_20180623":{
				"temperature":"20℃~24℃",
				"weather":"多云",
				"weather_id":{
					"fa":"01",
					"fb":"01"
				},
				"wind":"南风3-5级",
				"week":"星期六",
				"date":"20180623"
			},
			"day_20180624":{
				"temperature":"20℃~24℃",
				"weather":"多云",
				"weather_id":{
					"fa":"01",
					"fb":"01"
				},
				"wind":"南风3-5级",
				"week":"星期日",
				"date":"20180624"
			},
			"day_20180625":{
				"temperature":"20℃~28℃",
				"weather":"多云转晴",
				"weather_id":{
					"fa":"01",
					"fb":"00"
				},
				"wind":"南风3-5级",
				"week":"星期一",
				"date":"20180625"
			},
			"day_20180626":{
				"temperature":"22℃~27℃",
				"weather":"晴转多云",
				"weather_id":{
					"fa":"00",
					"fb":"01"
				},
				"wind":"南风3-5级",
				"week":"星期二",
				"date":"20180626"
			}
		}
	},
	"error_code":0
}
*/
