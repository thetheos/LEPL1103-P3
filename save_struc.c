#include <stdlib.h>
#include <stdio.h>

typedef struct point {
    int x;
    int y;
    int z;
} point_t;



int main(){
   return 0;
}


int save(point_t *pt, int size, char *filename) {
   int len = size*sizeof(point_t);
   int fd = open(filename, O_RDWR|O_CREAT,S_IRWXU);
   if(fd==-1)
   return -1;
   if(ftruncate(fd,len) == -1){
    if(close(fd)==-1)
    return -2;
    return -6;   
   }
   void* ptr = mmap(NULL, len, PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
   if(pointer == MAP_FAILED){
      if(close(fd)==-1)
      return -2;
      return -3
   }
   memocpy(ptr, (const void*) pt, len);
   int synchro = msync(ptr,len,MS_SYNC);
   if(synchro == -1){
     if(close(fd)==-1)
     return -2;
     return -5;  
   }
   
   int unmap = munmap(ptr,len);
   if(unmap == -1){
    if(close(fd)==-1)
    return -2;
    return -4;
   }
if(close(fd)==-1)
return -2;

return 0;

}

