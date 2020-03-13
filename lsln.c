//Benjamin Besic 3AHIF
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <dirent.h>

int main(int argc, char const *argv[]) {
  //gnu99 has to be used for compiling!
  struct dirent* direntry;
  struct stat attributes;
  DIR * dir=opendir(".");;

  while ((direntry = readdir(dir)) != 0)
  {
     if(stat(direntry->d_name, &attributes) < 0){
        return 1;
     }

     printf("\n");
     if(S_IFBLK & attributes.st_mode)
       printf("b");
     else if (S_IFREG & attributes.st_mode)
       printf("-");
     else if (S_IFCHR & attributes.st_mode)
       printf("c");
     else if (S_IFLNK & attributes.st_mode)
       printf("l");
     else if (S_IFDIR & attributes.st_mode)
       printf("d");

     printf((attributes.st_mode & S_IRUSR) ? "r" : "-");
     printf((attributes.st_mode & S_IWUSR) ? "w" : "-");
     printf((attributes.st_mode & S_IXUSR) ? "x" : "-");
     printf((attributes.st_mode & S_IRGRP) ? "r" : "-");
     printf((attributes.st_mode & S_IWGRP) ? "w" : "-");
     printf((attributes.st_mode & S_IXGRP) ? "x" : "-");
     printf((attributes.st_mode & S_IROTH) ? "r" : "-");
     printf((attributes.st_mode & S_IWOTH) ? "w" : "-");
     printf((attributes.st_mode & S_IXOTH) ? "x " : "- ");

     printf("%d ",attributes.st_uid);
     printf("%d ",attributes.st_gid);
     printf("%ld  \t",attributes.st_size);

     char time[18];
     strftime(time, 18, "%Y-%m-%d-%H-%M", localtime(&attributes.st_mtime));
     printf("%s ",time);
     printf("%s",direntry->d_name );
  }
  closedir(dir);
  printf("\n");
  return 0;
}
