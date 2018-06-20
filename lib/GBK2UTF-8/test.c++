#include "GBK_UTF8.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
	string answer="青岛，\n";
	answer.resize(answer.size()-4);
	cout<<GBK2UTF_8_X(UTF_82GBK(answer))<<endl;
	/*
	cout<<GBK2UTF_8("\xe1\xc0\xc9\xbd\xa3\xac\xa")<<endl;
	cout<<UTF_82GBK("静态模式")<<endl;
	

	char buf[100];
	u2g("静态模式",buf,100);
	cout<<buf<<endl;
	char buf2[100];
	g2u(buf,buf2,100);
	cout<<buf2<<endl;
	*/

	return 0;
}
