#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
  if(argc !=2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 0;
  }


  int fd = open("./myfile", O_RDWR|O_CREAT, 0644); 
  if (fd==-1) {
    perror("open");
    return -1;
  }q\
}