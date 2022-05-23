#include <stdlib.h>

#include <stdio.h>

/**
* @author Galen Q. Pellitteri
*
* wcat is meant to simply read through supplied files and print them to the console. There isnt much
* to this program to get hung up on.
*/

int main(int argc, char * argv[]) {

  if (argc == 0) {
    printf("Can not open file.");
    exit(1);
  } else {
    size_t len = 0;
    for (int i = 1; i < argc; i++) {
      char * buffer;
      FILE * fp = fopen(argv[i], "r");
      while (getline( & buffer, & len, fp) != EOF) {
        printf("%s", buffer);
      }
      fclose(fp);
    }
  }
  return 0;
}