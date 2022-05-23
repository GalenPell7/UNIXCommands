#include <stdlib.h>

#include <stdio.h>

#include <stdbool.h>

#include <string.h>

/**
* @author Galen Q. Pellitteri
* 
* wgrep is meant to search one or more files for a key word/phrase. If no files are 
* supplied, the program will wait for user input and grep through the supplied sequence of words.
*/

int main(int argc, char * argv[]) {
  char * prompt = NULL;
  char * line = NULL;
  size_t size = 0;
  if (argc == 1) {
    printf("wgrep: searchterm [file ...]\n");
    exit(1);
  } else if (argc == 2) {
    while (getline( & line, & size, stdin) != EOF) { // if no files are supplied, search user input.
      if (strstr(line, argv[1])) {
        printf("%s", line);
      }
    }
  } else {
    prompt = argv[1];
    for (int k = 2; k < argc; k++) { // go through files and search for the term.
      FILE * fp = fopen(argv[k], "r");
      if (fp == NULL) {
        printf("wgrep: cannot open file");
        exit(1);
      } else {
        while (getline( & line, & size, fp) != EOF) { // if you find the line, print it.
          if (strstr(line, prompt)) {
            printf("%s", line);
          }
        }
      }
      fclose(fp);
    }
  }
  return 0;
}