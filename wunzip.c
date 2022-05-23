/**
 * @author Galen Q. Pellitteri
 * wunzip is meant to unzip a file that was compressed using RLE(Run Length Encoding).
 * The compressed sorce file can be a combination of one or more files.
 */
#include <stdlib.h>

#include <stdio.h>

#include <ctype.h>

int main(int argc, char * argv[]) {

  if (argc == 1) {
    printf("wunzip: file1 [file2 ...]\n");
  } else {
    int character = 0;
    int count = 0;
    FILE * fp = fopen(argv[1], "r"); // open compressed file for reading.
    if (!fp) {
      printf("wunzip: cannot open file\n");
      exit(1);
    }
    while (fread( & count, sizeof(count), 1, fp)) { // read input file character by character and assign count.
      character = fgetc(fp); // get ASCII representation of character.
      for (int j = 0; j < count; j++) {
        printf("%c", character);
      }
    }
    fclose(fp); // close file
    printf("\n");
  }
  return 0;
}