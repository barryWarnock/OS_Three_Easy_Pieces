#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <wait.h>

int main(char* argv, int args) {
  int pipefds[2];
  pipe(pipefds);
  int pid = fork();
  if (pid == 0) {
      pid = fork();
      if (pid == 0) {
        wait(NULL);
        wait(NULL);
      } else {
        //writer process
        close(STDOUT_FILENO);
        close(pipefds[0]);
        dup(pipefds[1]);
        printf("Hello World!");
      }
  } else {
      //reader
      close(STDIN_FILENO);
      close(pipefds[1]);
      dup(pipefds[0]);
      char* buf = malloc(sizeof(char));
      while (read(STDIN_FILENO, buf, 1) != 0) {
        printf("%c", buf[0]);
      }
  }
  return 0;
}
