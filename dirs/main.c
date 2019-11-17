#include <stdlib.h>
#include <stdio.h>

#include <sys/stat.h>
// #include <fnctl.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(){
    DIR * d = opendir(".");
    int i;
    struct dirent * file;
    for (; file != NULL; file = readdir(d)){
        printf("%s", file->d_name);
        if (file->d_type == 4){
            printf(" is a directory");
        }
        printf("\n");
    }



}
