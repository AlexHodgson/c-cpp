#include <stdio.h>
struct TwoDPoint {
double x, y;
};


int main(void) {
	struct TwoDPoint a, b = {0.0 ,0.0}; //added struct and got rid of the _t so it would initialise a and b
	{
		char input [100];
		puts("Please enter the x and y coordinates of the 1st point , separated by a comma.");
		fgets(input , sizeof(input), stdin);
		sscanf(input ,"%lf,%lf", &(a.x), &(a.y)); //changed a.y to &(a.y) so the value is stored in the correct place
		
		
		puts("Please enter the x and y coordinates of the 2nd point , separated by a comma.");
		fgets(input , sizeof(input), stdin);
		sscanf(input ,"%lf,%lf", &(b.x), &(b.y)); //Changed %f to %lf so the values are stored as doubles
	}
	
	double x_dist = (a.x - b.x), y_dist = (a.y - b.y);
	printf("The square of the distance between the twopoints is: %f\n", (x_dist*x_dist)+(y_dist*y_dist));
	
return 0;
}
//The input handling doesn't have to be in a seperate block for the program to work, but doing it like this means that the array input[] isn't using memory when it isn't needed any more
