#include <stdlib.h>
#include <stdio.h>
#include "font.h"

#define asc2idx(asc) (asc-32)
void prsym(int idx) {
	
	int iline;
	char *(*symbol)[SYMBOL_HEIGHT] = &alphabet[idx];
	for(iline = 0; iline!=SYMBOL_HEIGHT; ++iline){
		puts((*symbol)[iline]);
		puts("\n");
	}
}

void printLine (int line, int argc2, char **argv2){
      int arg;
      for(arg = 1; arg != argc2; ++arg) {
		char *c = argv2[arg];
		while(*c) { 
			puts(alphabet[asc2idx(*c)][line]);
			++c;
		}
		if(arg!=argc2-1)
			puts(alphabet[asc2idx(' ')][line]);
		}
}


void printWord (int argc1, char **argv1){
    	int line;
	for(line = 0; line != SYMBOL_HEIGHT; ++line) {
	  printLine(line, argc1, argv1);
	  puts("\n");
	}	
		
}


/*int main(int argc, char **argv) {

  printWord(argc,argv);

	return 0;
}*/