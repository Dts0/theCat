#include <string>  
#include <json/json.h>  
#include <iostream>  
#include <fstream>  
using namespace std;  
  
void writeFileJson();//将信息保存为JSON格式  
  
int main(int argc, char *argv[])   
{  
    writeFileJson();  
      
    return 0;  
}  
  
//将信息保存为JSON格式  
void writeFileJson()  
{  
    //根节点  
    Json::Value root;  
      
    //根节点属性  
    root["name"] = Json::Value("Mike Jiang");  
    root["age"] = Json::Value(23);  
    root["sex_is_male"] = Json::Value(true);  
      
    //子节点  
    Json::Value partner;  
      
    //子节点属性  
    partner["partner_name"] = Json::Value("Galatea");  
    partner["partner_age"] = Json::Value(21);  
    partner["partner_sex_is_male"] = Json::Value(false);  
      
    //子节点挂到根节点上  
    root["partner"] = Json::Value(partner);  
      
    //数组形式  
    root["achievement"].append("ach1");  
    root["achievement"].append("ach2");  
    root["achievement"].append("ach3");  
      
    //直接输出  
    cout << "FastWriter:" << endl;  
    Json::FastWriter fw;  
    cout << fw.write(root) << endl << endl;  
      
    //缩进输出  
    cout << "StyledWriter:" << endl;  
    Json::StyledWriter sw;  
    cout << sw.write(root) << endl << endl;  
      
    //输出到文件  
    ofstream os;  
    os.open("demo.json");  
    os << sw.write(root);  
    os.close();  
      
    /* 
    //json文件内容如下： 
    { 
        "achievement" : [ "ach1", "ach2", "ach3" ], 
        "age" : 23, 
        "name" : "Mike Jiang", 
        "partner" : { 
            "partner_age" : 21, 
            "partner_name" : "Galatea", 
            "partner_sex_is_male" : false 
        }, 
        "sex_is_male" : true 
    } 
    */  
  
}  
