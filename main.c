#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[100];

  while(1) {
    /* Displays shell prompt, forces prompt to display before program exits
     * Gets user input with max of 100 char 
     */
    printf("shell>");
    fflush(stdout);
    fgets(input, 100, stdin);
    
    /* Removes newline kept from fgets
     * If user input was "exit", break the loop leave the program
     */
    input[strcspn(input, "\n")] = 0;
    if (strcmp(input, "exit") == 0) {
      break;
    }

    printf("You: %s", input);
  }

  return 0;
}
