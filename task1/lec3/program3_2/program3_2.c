#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
  int pid = fork();
  switch (pid) {
  case -1:
    perror("fork");
    return -1;
  case 0: // Child
    printf("my pid = %i, returned pid = %i\n", getpid(), pid);
    break;
  default: // Parent
    printf("my pid = %i, returned pid = %i\n", getpid(), pid);
    break;
  }
  return 0;
}
