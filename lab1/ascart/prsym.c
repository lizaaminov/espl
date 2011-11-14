#include <stdlib.h>
#include <stdio.h>
#include "font.h"

#define asc2idx(asc) (asc-32)
void prsym(int idx) {
	
	int iline;
	char *(*symbol)[SYMBOL_HEIGHT] = &alphabet[idx];
	for(iline = 0; iline!=SYMBOL_HEIGHT; ++iline)
		printf("%s\n", (*symbol)[iline]);
}


int main(int argc, char **argv) {

  	int line, arg;
	for(line = 0; line != SYMBOL_HEIGHT; ++line) {
		for(arg = 1; arg != argc; ++arg) {
			char *c = argv[arg];
			while(*c) { 
				printf("%s", alphabet[asc2idx(*c)][line]);
				++c;
			}
			if(arg!=argc-1)
				printf("%s", alphabet[asc2idx(' ')][line]);
		}	
		printf("\n");
	}

	return 0;
}
