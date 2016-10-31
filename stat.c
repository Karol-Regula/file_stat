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
    
    //printf("Size of file (bytes): %li\n", info.st_size);//printing size of file
    
    double out = 0;
    char * convert(int scale){
	scale--;
	if (scale == 0){
	    return "bytes";
	}
	if (scale == 1){
	    return "kilobytes";
	}
	if (scale == 2){
	    return "megabytes";
	}
	else{
	    return "failure";
	}
    }

    int scale = 0;
    double compare = 1;
    while(info.st_size > compare){
	compare *= 1024;
	scale ++;
    }
    printf("Size of file (%s): %f\n", convert(scale), info.st_size / compare * 1024);


    char * modes[] = {"---","--x","-w-","-wx","r--","r-x","rw-","rwx"};
    int other = info.st_mode % 8;
    int group = (info.st_mode / 8) % 8;
    int owner = (info.st_mode / 64) % 8;
    printf("File mode: %o\n", info.st_mode);//printing file permissions
    printf("File mode: %s%s%s\n", modes[owner], modes[group], modes[other]);
    

    
    char time[100]; 
    strftime(time, 100, "%a %b %d %T %Y", localtime(&(info.st_ctime)));//calculating time
    //note: can use gmtime() instead of localtime() to avoid locaion discrepancies
    printf("Time of last access: %s\n", time);//printing time

    printf("\n");
}
