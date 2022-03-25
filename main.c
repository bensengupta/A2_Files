#include "../include/senguptaBenjaminA2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  printf("============== READING FILES ==============\n");
  char *contents1 = readFile("test1.txt");
  char *contents2 = readFile("test2.txt");
  char *contents3 = readFile("test3.txt");
  if (contents1 == NULL) {
    printf("ERROR: File 1 not found.\n");
    return -1;
  }
  if (contents2 == NULL) {
    printf("ERROR: File 2 not found.\n");
    return -1;
  }
  if (contents3 == NULL) {
    printf("ERROR: File 3 not found.\n");
    return -1;
  }
  printf("Files OK\n");

  // printf("============== STRETCH ==============\n");
  // printf("Input: 'pizza'\n");
  // printf("User input: ");
  // char *stretchOutput = stretchMe("pizza");
  // printf("Output: '%s'\n", stretchOutput);

  printf("============== SPLIT ==============\n");
  printf("Splitting file 1\n");
  char words[MAX_WORDS][MAX_LENGTH];
  int numWords = splitMe(contents3, words);

  printf("%d words.\n", numWords);
  for (int i = 0; i < numWords; i++) {
    printf("Word %d: '%s'\n", i, words[i]);
  }

  printf("============== SHRINK ==============\n");
  {
    char stringToShrink[] = ".Hello! World?.";
    printf("Before: '%s'\n", stringToShrink);
    int numPunctuation = shrinkMe(stringToShrink);
    printf(" After: '%s'\n", stringToShrink);
    printf("Removed %d punctuation.\n", numPunctuation);
  }
  {
    char *stringToShrink = malloc(sizeof(char) * (strlen(contents3) + 1));
    strcpy(stringToShrink, contents3);
    printf("Before: '%s'\n", stringToShrink);
    int numPunctuation = shrinkMe(stringToShrink);
    printf(" After: '%s'\n", stringToShrink);
    printf("Removed %d punctuation.\n", numPunctuation);
  }

  printf("============== PALINDROME ==============\n");
  printf("mom sis madam: %d\n", isItAPalindrome("mom sis madam"));
  printf("m: %d\n", isItAPalindrome("m"));
  printf("mm: %d\n", isItAPalindrome("mm"));
  printf("nope mom: %d\n", isItAPalindrome("nope mom"));
  printf("mother sister madam: %d\n", isItAPalindrome("mother sister madam"));
  printf("(nothing): %d\n", isItAPalindrome(""));

  printf("============== SUFFIXES ==============\n");
  printSuffixes(contents3, 8, "otter");
}
