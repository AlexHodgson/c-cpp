//Warning: this depends on stdlib.h and string.h
//Fills a 5x5 array with random values between 0 and 255

#include <stdio.h>

void fill(unsigned char pic[5][5],int width,int height){
	int i;
	int j;
	for(i = 0 ; i < width; i++){
		for( j = 0; j < height; j++){
			pic[i][j] = rand() % 255;
		}
	}
}

void binOut(unsigned char pic[5][5]){
	FILE * output;
	output = fopen("/home/2288093h/cLabs/lab6/binGray","wb+");
	
	fprintf(output,"%s %c %c %c \n", "P5",5,5,255); //output header
	fwrite(pic,1,25,output);
	
	fclose(output);
	
	}


