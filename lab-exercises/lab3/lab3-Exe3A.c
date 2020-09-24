#include <stdio.h>
struct TwoDPoint {
double x, y;
};


int main(void) {
	struct TwoDPoint points[] = {{0.0 ,0.0},{0.0 ,0.0}}; //use an array instead of a , b
	{
		char input [100];
		puts("Please enter the x and y coordinates of the 1st point , separated by a comma.");
		fgets(input , sizeof(input), stdin);
		sscanf(input ,"%lf,%lf", &(points[0].x), &(points[0].y)); //changed a.y to points[0].y
		
		
		puts("Please enter the x and y coordinates of the 2nd point , separated by a comma.");
		fgets(input , sizeof(input), stdin);
		sscanf(input ,"%lf,%lf", &(points[1].x), &(points[1].y)); //Changed %f to %lf so the values are stored as doubles
	}
	
	double x_dist = (points[0].x - points[1].x), y_dist = (points[0].y - points[1].y);
	printf("The square of the distance between the twopoints is: %f\n", (x_dist*x_dist)+(y_dist*y_dist));
	
return 0;
}
//The input handling doesn't have to be in a seperate block for the program to work, but doing it like this means that the array input[] isn't using memory when it isn't needed any more
