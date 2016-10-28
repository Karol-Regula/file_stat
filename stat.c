#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
//#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

void main(){
    printf("\n");
    
    struct stat info;
    stat("stat.c", &info);//obtaining information about file
    
    printf("Size of file (bytes): %li\n", info.st_size);//printing size of file
    
    printf("File mode: %o\n", info.st_mode);//printing file permissions
    
    char time[100]; 
    strftime(time, 100, "%a %b %d %T %Y", localtime(&(info.st_ctime)));//calculating time
    //note: can use gmtime() instead of localtime() to avoid locaion discrepancies
    printf("Time of last access: %s\n", time);//printing time

    printf("\n");
}
