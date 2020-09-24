#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "printpgm.h"


int img[5][5];

int main(int argc, char *argv[])
{
	//Check for -h in the input
	if(argc > 1 && !strcmp(argv[1],"-h")){
		printf("gray2 creates a PGM file with random values of greyness, and outputs it as an array that can be stored in a file\n");
	}
	//Otherwise call the functions to create the image
	else{
		fill(img,5,5);
		toConsole(img);
	}
	return 0;
}

