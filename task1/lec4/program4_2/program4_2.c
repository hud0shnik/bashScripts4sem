#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char * argv[]) {

  int pipefd[2]; /*Массив файловых дескрипторов*/
  pid_t cpid;
  char buf;

  if (argc != 2) {
    /*неверное число аргументов командной строки*/
    fprintf(stderr, "Использование: %s <string>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  if (pipe(pipefd) == -1) {
    /*не смог открыть канал*/
    //выводит описание ошибки последнего системного вызова в stderr
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  cpid = fork();
  if (cpid == -1) {
    /*не смог породить процесс*/
    perror("fork");
    exit(EXIT_FAILURE);
  }
  
  if (cpid == 0) {
    /* Потомок читает из канала */
    close(pipefd[1]); /* Закрывает неиспользуемый конец для записи */
    while (read(pipefd[0], & buf, 1) > 0)
      write(STDOUT_FILENO, & buf, 1);
    write(STDOUT_FILENO, "\n", 1);
    close(pipefd[0]);
    _exit(EXIT_SUCCESS);
  } else {
    /* Родитель пишет значение argv[1] в канал */
    close(pipefd[0]); /* Закрывает неиспользуемый конец для чтения */
    write(pipefd[1], argv[1], strlen(argv[1]));
    close(pipefd[1]); /* Читатель видит EOF */
    wait(NULL); /* Ожидание потомка */
    exit(EXIT_SUCCESS);
  }
}