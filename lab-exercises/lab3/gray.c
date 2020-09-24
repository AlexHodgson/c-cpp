#include <stdio.h>

char sign[]= "P2"; //Info for the image header
int height = 5;
int width = 5;
int max = 255;

unsigned short img[5][5] = {{255,100,255,150,50},{255,100,255,150,50},{255,100,255,150,50},{255,100,255,150,50},{0,100,255,150,50}}; //Values for the image

int i;
int j;

int main(void){
	printf("%s %d %d %d \n", sign,height,width,max); //output header
	
	for(i = 0; i < 5; i++) { //Print the array as a square
		for(j = 0; j < 5; j++) {
			printf("%d ", img[i][j]);
			}
		printf("\n");
	} 
	
	return 0;
}
