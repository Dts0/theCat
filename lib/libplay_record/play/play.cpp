#include <stdlib.h>
#include <string.h>
#include "play.h"

using namespace std;

void play(string filepath){
    system(("play "+filepath).c_str());
}
