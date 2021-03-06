#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1

int main(int argc, char *argv[]) {
  FILE *fp1, *fp2;
  unsigned char buf1[BUFFER_SIZE];
  unsigned char buf2[BUFFER_SIZE];
  int c=0;
  int same=0;

  if(argc!=3) {
    printf("Usage: compare <file 1> <file 2>\n");
    exit(1);
  }

  /* open first file */
  if((fp1 = fopen(argv[1], "rb"))==NULL) {
    printf("Cannot open first file.\n");
    exit(1);
  }

  /* open second file */
  if((fp2 = fopen(argv [2], "rb"))==NULL) {
    printf("Cannot open second file.\n");
    exit(1);
  }

  /* compare the files */

  while(fread(buf1, BUFFER_SIZE, 1, fp1)) {
    if (fread(buf2, BUFFER_SIZE, 1, fp2)) {
      if (buf1[0] != buf2[0]) {
        same = 1;
        printf("byte %i -%i +%i\n", c, buf1[0], buf2[0]);
      }
    } else {
      break;
    }
    ++c;
  }

  if(fclose( fp1 ) == EOF) {
    printf("Error closing first file.\n");
    exit(1);
  }

  if(fclose( fp2 ) == EOF) {
    printf("Error closing second file.\n");
    exit(1); 
  }

  return 0;
}
