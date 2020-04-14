#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(char* argv, int args) {
  int pipefds[2];
  pipe(pipefds);
  int pid = fork();
  if (pid == 0) {
      char* buffer = malloc(sizeof(char));
      while (read(pipefds[1], buffer, 1) == 0) {} 
      printf("goodbye");
  } else {
    printf("hello\n");
    write(pipefds[0], "done", 4);
  }
  return 0;
}
