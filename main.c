# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/types.h>
# include <errno.h>
# include <unistd.h>

int main(int argc, char* argv[]){
    char dir [50];
    if (argc <= 1){
        printf("Showing current directory, if you want a different directory add DIR=<directory> after make run\n\n" );
        strcpy(dir,".");
    } else {
        strcpy(dir,argv[1]);
    }
    printf("Statistics for directory: %s\n", dir);
    DIR * d = opendir(dir);
    int i;
    struct dirent * directory;
    struct stat *file= malloc(sizeof(struct stat));
    int totalSize = 0;
    for (; directory != NULL; directory = readdir(d)){
        stat(directory->d_name, file);
        totalSize += file->st_size;
        if (directory->d_type == DT_DIR){
            printf("Directory: %s\n", directory->d_name);
        }
        if (directory->d_type == DT_REG){
            printf("Regular File: %s\n", directory->d_name);
        }
    }
    printf("Total size is %d\n", totalSize);
}
