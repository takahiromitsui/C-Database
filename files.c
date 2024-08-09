#include <stdio.h>
#include <fcntl.h>

int main() {
  int fd = open("./abb", O_RDONLY); 
  if (fd==-1) {
    perror("open");
    return -1;
  }
}