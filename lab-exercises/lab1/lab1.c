#include <stdio.h> //Need to import io to be able to  use printf
int k = 4;
int main(void) {
	int i = 50;
	unsigned int j = i * 2;
	double k = 1.0
//No need for the braces here
{
	float i = 5.0;
	printf("The value of i is %3d\n", i); //use %3d here as it was previously expecting a float, and i is an int
	k = i * j;
	i *= 6;
}
	//removed "double j" here as it was an incompatiable type and j isn't used again after this point
	i = k + i; //or i += k
	printf("Now , the value of i is %d\n", i);
	return 0;
}
