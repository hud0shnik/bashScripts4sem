#include <unistd.h>

int main() {

  char * args[] = {
    "/bin/cat",
    "--help",
    NULL
  };

  execve("/bin/cat", args, environ); // Unreachable
  
  return 1;
}