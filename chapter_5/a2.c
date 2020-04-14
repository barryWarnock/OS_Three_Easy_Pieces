#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(char* argv, int args) {
  int fd = open("a2.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
  char* print_str = malloc(sizeof(char)*100);
  int pid = fork();
  for (int i = 0; i < 1024; i++) {
    sprintf(print_str, "%d:%d\n", pid, i);
    write(fd, print_str, strlen(print_str));
  }
  return 0;
}
