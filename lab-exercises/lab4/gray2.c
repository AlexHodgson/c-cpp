#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i;
int j;
int img[5][5];

//Fills a 5x5 array with random values between 0 and 255
void fill(int pic[5][5],int width,int height){
	for( i = 0 ; i < width; i++){
		for( j = 0; j < height; j++){
			pic[i][j] = rand() % 255;
		}
	}
}

void toConsole(int pic[5][5]){
	printf("%s %d %d %d \n", "P2",5,5,255); //output header
	
	for(i = 0; i < 5; i++) { //Print the array as a square
		for(j = 0; j < 5; j++) {
			printf("%d ", img[i][j]);
			}
		printf("\n");
	} 
}
	

int main(int argc , char *argv[])
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

