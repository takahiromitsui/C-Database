#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/stat.h>

struct database_header_t {
  unsigned short version;
  unsigned short employees;
  unsigned int filesize;
};


int main(int argc, char *argv[]) {
  struct database_header_t head= {0};
  struct stat dbStat = {0};

  if(argc !=2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 0;
  }


  int fd = open(argv[0], O_RDWR|O_CREAT, 0644); 
  if (fd==-1) {
    perror("open");
    return -1;
  }

  if(read(fd, &head, sizeof(head)) != sizeof(head)) {
    perror("read");
    close(fd);
    return -1;
  }

  printf("DB_Version: %u\n", head.version);
  printf("DB Number of Employees: %u\n", head.employees);
  printf("DB File Length: %u\n", head.filesize);

  if (fstat(fd, &dbStat) < 0) {
    perror("stat");
    close(fd);
    return -1;
  }
  printf("DB File Length, reported by stat: %lld\n", dbStat.st_size);

  if (dbStat.st_size != head.filesize) {
    printf("GET OUTTA HERE HACKER!\n");
    close(fd);
    return -2;
  };

  close(fd);
  return 0;
}