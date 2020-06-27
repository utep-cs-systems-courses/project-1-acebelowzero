#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


/* Initialize the linked list to keep the history. */
List* init_history() {
  List *list = (List *)malloc(sizeof(List));
  list->root = NULL;
}



/* gets the total length of the string */
int str_length(char *str) {

  int count;
  while(*str != '\0'){
    count++;
  }
  return count;
}



/* Add a history item to the end of the list.
       List* list - the linked list
       char* str - the string to store
*/
void add_history(List *list, char *str) {
  // create pointer to new Item
  Item *new_item = (Item *)malloc(sizeof(Item));

  // add char array str to new_item
  new_item->str  = copy_str(str, str_length(str));
  new_item->next = NULL;

  // if empty then head = tail = new_item
  if (list->root == NULL) {
    list->root = new_item;
    new_item->id = 1;
  }

  else {
    int prev_id      = list->root->id;
    list->root->next = new_item;
    list->root       = new_item;
    new_item->id     = prev_id + 1;
  }
 
}



/* Retrieve the string stored in the node where Item->id == id.
       List* list - the linked list
       int id - the id of the Item to find */
char *get_history(List *list, int id) {
  // make sure id is within the list bounds
  if (list->root->id < id) {
    printf("Error: Index out of bounds, Index must be less than %d\n", list->root->id);
    return NULL;
  }
  
  Item *current = list->root;
  
  // loop through the list until id is found.
  while(current->id != id) {
    current = current->next;
  }

  return current->str;
}

/* Print the entire contents of the list. */
void print_history(List *list) {

  Item *current = list->root;

  while (current != NULL) {
    printf(" %s ", current->str);
    current = current->next;
  }
  printf("\n");

}

/* Free the history list and the strings it references. */
void free_history(List *list) {

  Item *current = list->root;
  Item *next;

  while (current != NULL)
    {
      // store the address of the next Item before freeing the current Item
      next = current->next;
      free(current->str);
      free(current);
      current = next;
    }

}




