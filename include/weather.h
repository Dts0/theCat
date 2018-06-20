#ifndef WEATHER_H
#define WEATHER_H

#include <string>
#include <list>

bool weather_judgeFunc(std::string cmd);
std::string weather_execFunc(int numP=0,std::list<long> pList=std::list<long>());

#endif // !WEATHER_H
