#include <stdio.h>


int main(void){

	char op, buffer[100];
	float x, y, ans;

	printf("\nEnter a number, an operation and a number: ");
	fgets(buffer,sizeof(buffer),stdin);
	sscanf(buffer, "%f %c %f", &x, &op, &y);
	
	switch(op){
		case '+':
			ans = x + y;
			break;
		case '-':
			ans = x - y;
			break;
		case '/':
			ans = x / y;
			break;
		case '*':
			ans = x * y;
		}
		
	printf("The result is: %f \n", ans);
	return 0;
}
