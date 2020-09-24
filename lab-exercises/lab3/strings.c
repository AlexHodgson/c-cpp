#include <string.h>
#include <stdio.h>

char text[100];
int i;
int hasUpper;

int main(void)
{
	printf("Enter a string: "); //Inputs the string
	fgets(text,sizeof(text),stdin);
	
	printf("The input string is %d chars long\n",strlen(text));
	
	hasUpper = 0; // Use to check if there are any uppercase letters
	for(i = 0; i < strlen(text); i++){
		if(isupper(text[i])){ // Changes upper to lowercase
			hasUpper = 1;
			text[i] = tolower(text[i]);
		}
	}
	if(hasUpper){ //Prints string if there were uppercase letters
		printf("%s",text);
	}
	else{
		printf("The string was all lowercase\n");
	}
	
	return 0;
}

