#include <math.h>

//Calculate the real offset of the complex cube roots of a real, given the real root
double re_complexroots(double);

//Calculate the imaginary parts of the complex cube roots of a real, given the real root
double im_complexroots(double);

//try to parse input appropriately
double validate_input(int argc ,char * argv[]);

int main(int argc ,char * argv[]) {
	
	double x, cub_x , re_cub_x , im_cub_x;

	//get input and process it
	x = validate_input(argc , argv);
	cub_x = cbrt(x);
	re_cub_x = re_complexroots(cub_x);
	im_cub_x = im_complexroots(cub_x);

	printf("The cube roots of %f are %f, %f + %fi and %f - %fi.\n", x, cub_x , re_cub_x , im_cub_x , re_cub_x ,im_cub_x );
	
	return 0;

	}

