#include <stdio.h>
#include <unistd.h>

int main(char* argv, int args) {
  int x = 7;
  int pid = fork();
  printf("%d:%d\n", pid, x);
  x = pid/2;
  printf("%d:%d\n", pid, x);
  return 0;
}
