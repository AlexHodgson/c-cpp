#include "turtle.h"
#include <math.h>
#include <stdio.h>
#include <string.h>



int main(int argc, char *argv[]){
	int i;
	int n;
	double outer_angle;
	
	//n is the number of sides for the polygon
	if(strcmp(argv[0],"./square") == 0){
		n = 4;
	}
	else if(argc == 1){
		printf("Please provide a number of sides\n");
		exit(1);
	}
	else{
		sscanf(argv[1],"%d",&n);
}

	outer_angle = 360.0/n;
	
	//creates and clears the canvas
	turtle_init(256,256);
	turtle_reset;
	
	for(i = 0 ; i < n ; i++){
		turtle_turn_left(outer_angle);
		//use 10 as side length for simplicity
		turtle_forward(10);
	}
	
	void turtle_save_png("mylogo.png");
	
	return 0;
}
