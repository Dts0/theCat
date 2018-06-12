#include <stdlib.h>
#include <string.h>
#include "play.h"

void play(string file){
    system(("play "+file).c_str());
}
