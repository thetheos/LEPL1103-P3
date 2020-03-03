#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int file_exists(char *filename){
  int fd = open(filename,O_RDONLY);
  if(fd == -1)
  return -1;
  close(fd); 
  return 0;
}


int main(){
   printf("out :%i",file_exists("test"));
   return 0;
}


