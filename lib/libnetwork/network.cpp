#include "network.h"
#include <stdlib.h>
#include <sstream>

using namespace std;

void doGet(std::string host,std::string para,std::string response,int port){
    stringstream cmd;
    cmd<<"python $CAT_HOME/buf/python/doGet.py '"<<host;
	if(port!=80)
        cmd<<":"<<port;
    cmd<<"'";
    if(""!=para)
        cmd<<" '"<<para<<"'";
    else cmd<<" ''";
    cmd<<" '"<<response<<"'";
	system(cmd.str().c_str());
}
