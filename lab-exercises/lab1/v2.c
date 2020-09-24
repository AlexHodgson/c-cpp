#include <stdio.h>  //need to import io to allow printf to be called
int k = 4; //Has file scope
int main(void) {
	int i = 50;
	unsigned int j = i * 2;
	double k = 1.0; // missing semicolon :( 
	
{
	float i = 5.0;
	printf("The value of i is %3f\n", i);
	k = i * j;
	i *= 6;
	printf("i is now a float with value %3.2f\n",i);
	printf("k is now a double with value %3.2f\n",k);
	
	//end of float i scope
}
	(double) j; //Still gives a warning as j is not used for anything after this point
	i = k + i; //or i += k
	printf("Now , the value of i is %d\n", i);
	return 0;
}		// end of i,j and double k scope
