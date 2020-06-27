#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"


#define MAX 50

/* print character array */
void print(char *str) {
  while (*str != '\0') {
    printf("%c", *str);
    str++;
  }
  printf("\n\n");
}


/* Simple user interface to tokenize and store users input */
int main() {
  
  // character array of length 50
  char str[MAX];

  // initialize linked list to store user history
  List *history = init_history();

  printf("Enter a string to get started or (enter q to exit)\n");

  // continue to get user input until the user exits using 'e'
  while (*str != 'q') {
    printf(">");
    fgets(str, MAX, stdin);

    if (*str != 'q' && *str != '!') {
      printf("You entered: %s\n", str);

      // tokenizes the users input 
      char **token = tokenize(str);
    
      printf("The tokenized string is: \n\n");

      print_tokens(token);
      free_tokens(token);

      // add character string to history
      add_history(history, str);
      }

     // get specified history item at index
    if (*str == '!') {
      int index = (int)(str[1] - '0');

      char *prev_str = get_history(history, index);
      if (prev_str != NULL) {
	printf("The History item is:\t");
	print(prev_str);
	
	printf("\n");
      }
    }
  }
  
  printf("Your input history is:\n\n");
  print_history(history);
  
  // free linked list
  free_history(history);
  printf("History has been cleared\n\n");
  
  printf("System exited successfully!\n\n");
  
  return 0;
}
