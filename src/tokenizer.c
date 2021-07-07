#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"



/* Return true (non-zero) if c is a whitespace characer

   ('\t' or ' ').  

   Zero terminators are not printable (therefore false) */

int space_char(char c) {
  return (c == '\t' || c == ' ' || c == '\n') ? 1 : 0;
}


/* Return true (non-zero) if c is a non-whitespace 

   character (not tab or space).  

   Zero terminators are not printable (therefore false) */
int non_space_char(char c) {
  return (space_char(c) || c == '\0') ? 0 : 1;
}

/* Returns a pointer to the first character of the next 

   space-separated word in zero-terminated str.  Return a zero pointer if 

   str does not contain any words. */
char *word_start(char* str){
  if (*str == '\0') {
    return 0;
  }
  
  // skip white space
  while (space_char(*str)) {
    str++;
  }
  
  // return the begining of the next word.
  return str;
}

char *word_terminator(char* str){
    // skip non-white space
  while (non_space_char(*str)) {
    str++;
  }

   // return the begining of the end of a word.
  return str;
}
/*
we take in the string str or character array
then we iterate throught the string/characer array until
we see a space then we increment wordCount.
*/
int count_words(char* str){
    int wordCount=0;
    int length;
    length = strlen(str);
    for(int i = 0; i < length; i++){
      if(str[i] == ' '){
        wordCount++;
      }
    }
    wordCount+=1;
    return wordCount;
}

/*
we take in first letter of the word, along with lenght of the word. then
make allocate space in memory for a new array called
wordHolder, we then add each letter of the word to the wordholder array 
and wordholder is returned 
*/
char *copy_str(char* insertStr, short len){
    int i;
    char *wordHolder;
    wordHolder = (char *)malloc(sizeof(char) * (len+1));
    for(i = 0; i < len; i++){
        wordHolder[i] = insertStr[i];
    }
    wordHolder[i] = '\0';
    return wordHolder;
}
/*
in tokenize we are seperating the character array or string by ' '
it first finds the total words with count_words then finds the length, start and end letter 
of each word. we then call the copy_str method to add it to a temp array then send it back to tokenize
and add it to the array

   For example, tokenize("hello world string") would result in:

     tokens[0] = "hello"

     tokens[1] = "world"

     tokens[2] = "string" 

     tokens[3] = 0
*/
char** tokenize(char* str){
    int totalWords = count_words(str);
    printf("%d\n", totalWords);
    char **array;
    array = (char **)malloc(sizeof(char*) * (++totalWords));

    //filling the array with individual words
    int diff = 0;
    int i;
    for(i = 0; i < totalWords-1; i++){
        str = word_start(str);
        // find difference in length
        diff = word_terminator(str) - str;
        // add new allocated string to array
        array[i] = copy_str(str, diff);
        // update pointer p to next word
        str = word_terminator(str);
        
    }
    array[i] = '\0';
    return array;
}

/*
this prints each character in the array from tokenize method.

*/

void print_tokens(char **tokens){
  int i, j;
  for(i = 0; tokens[i] != NULL; i++){
    for(j = 0; tokens[i][j] != '\0'; j++){
      printf("%c", tokens[i][j]);
    }
    printf("\n");
  }
}

/* Frees all tokens and the vector containing them. 
removing each token from memory */

void free_tokens(char **tokens) {
  int i;
  for (i = 0; tokens[i] != NULL; i++) {
    free(tokens[i]);
  }

  free(tokens);
}





