#include <stdio.h>
#include <math.h>
#include <errno.h> /* содержит объявления для errno */

int main(void) {

  /* приведет к возникновению ошибки области определения */
  asin(10.0);

  if (errno == EDOM)
    perror("Program Error Test");

  return 0;
}