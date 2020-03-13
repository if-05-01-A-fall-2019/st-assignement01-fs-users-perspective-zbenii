//Benjamin Besic 3AHIF
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {
  //gnu99 has to be used for compiling!
  struct stat attributes;

  printf("\n");
  printf("--------------------%s--------------------\n",argv[1]);
  printf("\n");
  printf("File Type: \t\t");

  if(S_IFBLK & attributes.st_mode)
    printf("Block device");
  else if (S_IFDIR & attributes.st_mode)
    printf("Directory");
  else if (S_IFCHR & attributes.st_mode)
    printf("Character device");
  else if (S_IFLNK & attributes.st_mode)
    printf("Symbolic link");
  else if (S_IFREG & attributes.st_mode)
    printf("Regular file");

  printf("\n");
  printf("Access privileges:\t");

  if (attributes.st_mode & S_IWUSR)printf("w");
    else printf("-");
  if (attributes.st_mode & S_IXUSR)printf("x");
    else printf("-");
  if (attributes.st_mode & S_IRGRP)printf("r");
    else printf("-");
  if (attributes.st_mode & S_IRUSR)printf("r");
    else printf("-");
  if (attributes.st_mode & S_IWGRP)printf("w");
    else printf("-");
  if (attributes.st_mode & S_IWOTH)printf("w");
    else printf("-");
  if (attributes.st_mode & S_IXGRP)printf("x");
    else printf("-");
  if (attributes.st_mode & S_IROTH)printf("r");
    else printf("-");
  if (attributes.st_mode & S_IXOTH)printf("x");
    else printf("-");

  printf("\n");

  printf("inode-Number: \t\t%ld\n",attributes.st_ino);
  printf("Device Numbers: \tdev = %ld; rdev = %ld\n",attributes.st_dev, attributes.st_rdev);
  printf("Number of Links: \t%ld\n",attributes.st_nlink);
  printf("UID: \t\t\t%d\n",attributes.st_uid);
  printf("GID: \t\t\t%d\n",attributes.st_gid);
  printf("File size: \t\t%ld\n",attributes.st_size);
  printf("Last access: \t\t%s",asctime(gmtime(&attributes.st_atime)));
  printf("Last modification: \t%s",asctime(gmtime(&attributes.st_mtime)));
  printf("Last inode change: \t%s",asctime(gmtime(&attributes.st_ctime)));
  return 0;
}
