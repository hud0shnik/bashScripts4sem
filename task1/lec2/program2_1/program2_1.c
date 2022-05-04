#include <stdlib.h>
#include <stdio.h>

int main() {

  int * array = NULL;
  unsigned length, i;
  printf("Enter length of array: ");
  scanf("%d", &length);

  if (length > 0) {
    //При выделении памяти возвращается указатель.
    //Если память не была выделена, то возвращается NULL
    if ((array = (int * ) malloc(length * sizeof(int))) != NULL) {
      for (i = 0; i < length; i++) {
        array[i] = i * i;
      }
      printf("Allocated %lu bytes\n", length * sizeof(*array));
    } else {
      printf("Error: can't allocate memory\n");
    }
  }

  //Если переменная была инициализирована, то очищаем её
  if (array != NULL) {
    free(array);
  }
  return 0;
}
