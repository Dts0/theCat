#include<stdio.h>
#include<string>
#include<stdlib.h>

using namespace std;
int main(){
	string file="../../test.pcm";
	system(("play "+file).c_str());
	return 0;
}

