#include<iostream>
#include<stdlib.h>
#include<string>
#include"reply.h"

using namespace std;

int main(int argc,char* argv[]){
	replyInit();
	//cout<<argc<<argv[1];
	if(argv[1]!=NULL)
        cout<<reply(argv[1]);
    else cout<<"需要输入\n";
	return 0;
}
