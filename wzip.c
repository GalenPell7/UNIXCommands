#include <stdlib.h>

#include <stdio.h>

#include <string.h>

#include <stdbool.h>

/**
 * @author Galen Q. Pellitteri
 *
 * wzip is meant to read in one or more files and compress their contents within a single
 * compressed file. The resultant file will include the 4 byte integer in hex form
 * that represents the amount of the character that follows it.
 */

int main(int argc, char * argv[]) {
  char * line = NULL;
  size_t len = 0;
  if (argc == 1) { // no files supplied.
    printf("wzip: file1 [file2 ...]");
  } else {
    char current;
    int count = 0;
    bool started = false;
    for (int i = 1; i < argc; i++) {
      FILE * fp = fopen(argv[i], "r");
      if (!fp) { // file cannot be opened.
        printf("wzip: cannot open file\n");
      } else {
        while (getline( & line, & len, fp) != EOF) { // read line by line.
          if (started == false) { // assign current if its the first file. 
            current = line[0];
            started = true;
          }
          for (int j = 0; j < len; j++) { // traverse line and compare.
            if (current == line[j]) {
              count++;
            } else {
              fwrite( & count, sizeof(count), 1, stdout);
              fwrite( & current, sizeof(current), 1, stdout);
              current = line[j];
              count = 1;
            }
          }
        }
      }
      fclose(fp);
    }
  }
  return 0;
}