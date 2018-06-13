#include "network.h"
#include <stdlib.h>

using namespace std;

bool sendMessage(std::string message,std::string address,std::string port){
	string msg="nc -l "+address+" port\n"+message+"\n";
	system(msg.c_str());
}
