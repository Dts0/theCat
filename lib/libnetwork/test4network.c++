#include<iostream>
#include<stdlib.h>
#include<locale.h>
#include<stdio.h>
#include<string.h>
#include"network.h"
using namespace std;

int main(){
	doGet("v.juhe.cn/weather/index",
	"cityname=%E5%B4%82%E5%B1%B1&dtype=xml&format=2&key=1218059ee4c3713769eed2335e8a77c6",
	"result.txt",80);
	return 0;
}
