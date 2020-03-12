#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[]){
    int fd = open(argv[1],O_RDWR);
    char text[256];
    read(fd,text,sizeof(text));

    fd=open(argv[2],O_WRONLY);

    if(fd<0){
      fd=creat(argv[2],S_IRWXU);
      fd=open(argv[2],O_WRONLY);
    }

    write(fd,text,sizeof(text));

    return 0;
}
