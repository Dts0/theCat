#include "word2voice.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;

void word2voice(std::string text,std::string outputfile){
	ofstream out("reply.txt");
	out<<text;
	out.close();
	string cmd="python $CAT_HOME/buf/python/word2voice.py\n";
	system(cmd.c_str());
	//system("play result.mp3\n");
	if(outputfile!="result.mp3"){
		cmd="mv ./result.mp3 "+outputfile+"\n";
		system(cmd.c_str());
	}
}
