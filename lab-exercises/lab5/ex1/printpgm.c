//Warning: this depends on stdio.h, stdlib.h and string.h

//Fills a 5x5 array with random values between 0 and 255
void fill(int pic[5][5],int width,int height){
	int i;
	int j;
	for(i = 0 ; i < width; i++){
		for( j = 0; j < height; j++){
			pic[i][j] = rand() % 255;
		}
	}
}

void toConsole(int pic[5][5]){
	printf("%s %d %d %d \n", "P2",5,5,255); //output header
	int i;
	int j;
	for(i = 0; i < 5; i++) { //Print the array as a square
		for(j = 0; j < 5; j++) {
			printf("%d ", pic[i][j]);
			}
		printf("\n");
	} 
}



