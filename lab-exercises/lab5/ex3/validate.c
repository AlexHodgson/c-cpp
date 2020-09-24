#include <stdio.h>

//Make sure that there is only one parameter given, and that it is a double
double validate_input(int argc ,char* argv[]) {
	
	if(2!=argc) {
		fputs("Too many inputs - just enter one double!", stderr);
		exit(1);
		
		}
		
	//Get the value given by the user	
	double val;
	int parsed = sscanf(argv[1],"%lf", &val );

	if(0 == parsed) {
		fputs("Could not parse input as a double!", stderr);
		exit(1);
		}
	
	return val;
}
