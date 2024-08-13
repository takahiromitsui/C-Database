#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#include "parse.h"
#include "common.h"

int validate_db_header(int fd, struct dbheader_t **headerOut) {
  if (fd < 0) {
    printf("Got a bad FD from the user\n");
    return STATUS_ERROR;
  }
  struct dbheader_t *header = calloc(1, sizeof(struct dbheader_t));
  if (header == -1) {
    printf("Malloc failed to create db header\n");
    return STATUS_ERROR;
  }
  if (read(fd, header, sizeof(struct dbheader_t)) != sizeof(struct dbheader_t)) {
    perror("read");
    free(header);
    return STATUS_ERROR;
  };
  header-> version = ntohs(header->version);
  header->count =ntohl(header->count);
  header->magic =ntohl(header->magic);
  header->filesize =ntohl(header->filesize);

  if(header->magic !=HEADER_MAGIC) {
    printf("Impromper header magic\n");
    free(header);
    return STATUS_ERROR;
  };

  if(header->version !=1) {
    printf("Impromper header version\n");
    free(header);
    return STATUS_ERROR;
  };

  struct stat dbstat = {0};
  fstat(fd, &dbstat);
  if(header->filesize != dbstat.st_size) {
    printf("Corrupted database\n");
    free(header);
    return STATUS_ERROR;
  };
};

int create_db_header(int fd, struct dbheader_t **headerOut) {
  struct dbheader_t *header = calloc(1, sizeof(struct dbheader_t));
  if (header == -1) {
    printf("Malloc failed to create db header\n");
    return STATUS_ERROR;
  }


  header->version = 0x1;
  header->count = 0;
  header->magic = HEADER_MAGIC;
  header->filesize = sizeof(struct dbheader_t);
  *headerOut = header;
  return STATUS_SUCCESS;
}