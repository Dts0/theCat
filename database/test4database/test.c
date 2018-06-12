#include<sqlite3.h>
#include<stdlib.h>
#include<stdio.h>
int main(int argc, char **argv) {
    sqlite3_os_init();
    char* filename = "database.db";
    sqlite3 *db = NULL;
    if (sqlite3_open(filename, &db)) {
    } else {
        printf("open sqlite file %s succeed\n", filename);
    }
    return 1;
}
