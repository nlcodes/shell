#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/* Simple shell program which reads user input,
 * tokenizes commands, and implements program exit command
 */
int main() {
  char input[100];

  while(1) {
    /* Display shell prompt and collect user input */
    printf("shell>");
    fflush(stdout);
    fgets(input, 100, stdin);
    
    /* Remove newline and implement exit command */
    input[strcspn(input, "\n")] = 0;
    if (strcmp(input, "exit") == 0) {
      break;
    }

    /* Create array of pointers to store command line arguments */
    char *clargs[20];
    char *token = strtok(input, " ");
    int i = 0;

    /* Create array of cli arguments */
    while(token != NULL && i < 19) {
      clargs[i] = token;
      token = strtok(NULL, " ");
      i++;
    }
    clargs[i] = NULL;

    /* Test print tokens */
    printf("Tokens:\n");
    for(int j = 0; clargs[j] != NULL; j++) {
      printf("arg: %s\n", clargs[j]);
    }
  }

  return 0;
}
