#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
//#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <math.h>

//returns prefix to B
char convert(int scale){
  scale--;
  if (scale == 0){
    return '\0';
  }
  if (scale == 1){
    return 'K';
  }
  if (scale == 2){
    return 'M';
  }
  else{
    return 'G';
  }
}

void main(){
    printf("\n");

    char *filename = "b.md";
    struct stat info;
    stat("b.md", &info);//obtaining information about file
    stat(filename, &info);//obtaining information about file
    printf("Name of file: %s\n", filename);
    
    double out = 0;

    //scale conversion
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
    //printf("Size of file (bytes): %li\n", info.st_size);//printing size of file
    printf("Size of file: %.1f %sB\n", info.st_size / compare * 1024, convert(scale)); //%.1f (1 decimal place)
    
    //file mode conversion
    char out2[10] = {0};
    int n = info.st_mode;
    out2[0] = '-';
    out2[1] = (n & S_IRUSR ) ? 'r' : '-';
    out2[2] = (n & S_IWUSR ) ? 'w' : '-';
    out2[3] = (n & S_IXUSR ) ? 'x' : '-';
    out2[4] = (n & S_IRGRP ) ? 'r' : '-';
    out2[5] = (n & S_IWGRP ) ? 'w' : '-';
    out2[6] = (n & S_IXGRP ) ? 'x' : '-';
    out2[7] = (n & S_IROTH ) ? 'r' : '-';
    out2[8] = (n & S_IWOTH ) ? 'w' : '-';
    out2[9] = (n & S_IXOTH ) ? 'x' : '-';

    
    printf("File mode: %o\n", info.st_mode);//printing file permissions
    printf("File mode alternate: %s\n", out2);

    char * modes[] = {"---","--x","-w-","-wx","r--","r-x","rw-","rwx"};
    int other = info.st_mode % 8;
    int group = (info.st_mode / 8) % 8;
    int owner = (info.st_mode / 64) % 8;
    //printf("File mode: %o\n", info.st_mode);
    printf("File mode alternate2: %s%s%s\n", modes[owner], modes[group], modes[other]);


    char time[100];
    strftime(time, 100, "%a %b %d %T %Y", localtime(&(info.st_ctime)));//calculating time
    //note: can use gmtime() instead of localtime() to avoid locaion discrepancies
    printf("Time of last access: %s\n", time);//printing time

    printf("\n");
    //yawata159
}
