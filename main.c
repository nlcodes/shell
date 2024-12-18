#include <stdio.h>
#include <stdlib.h>

int main() {
  char input[100];

  while(1) {
    printf("shell>");
    fflush(stdout);

    fgets(input, 100, stdin);
    printf("You: %s", input);
  }
  return 0;
}
