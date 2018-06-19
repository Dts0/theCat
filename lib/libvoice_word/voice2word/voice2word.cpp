#include "voice2word.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;

std::string voice2word(std::string filepath){
	string cmd="python $CAT_HOME/buf/python/voice2word.py "+filepath;
	system(cmd.c_str());
	ifstream in("result.txt");
	ostringstream tmp;
	tmp << in.rdbuf();
	in.close();
	return tmp.str();
}
