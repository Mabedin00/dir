# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/types.h>
# include <errno.h>
# include <unistd.h>


int main(){
    DIR * d = opendir(".");
    int i;
    struct dirent * directory;
    struct stat file;
    for (; directory != NULL; directory = readdir(d)){
        stat(directory->d_name, &file);
        printf("%s has a size of %d", directory->d_name, file.st_size);
        if (directory->d_type == DT_DIR){
            printf(" and is a directory");
        }
        printf("\n");
    }

}
