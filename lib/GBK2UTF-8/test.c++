#include "GBK_UTF8.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
	cout<<GBK2UTF_8("\xbe\xb2\xcc\xac\xc4\xa3\xca\xbd")<<endl;
	cout<<UTF_82GBK("静态模式")<<endl;
	cout<<UTF_82GBK_X("静态模式")<<endl;

	char buf[100];
	u2g("静态模式",buf,100);
	cout<<buf<<endl;
	char buf2[100];
	g2u(buf,buf2,100);
	cout<<buf2<<endl;


	return 0;
}
