#include <stdio.h>

int num;
int rfactorial(int i);

int factorial(int i){
	int total = 1;
		while(i > 1) { //Loop over all numbers smaller than i and multiply them together
		total *= i;
		i--;
	}
	return total;
}

int rfactorial(int i){
	if(i == 1){ //Keep on multiplying by i-1 until you reach 1
		return i;
	}
	else{
		return i*rfactorial(i-1); 
	}
}
	
		
int main(int argc , char *argv[]){
	num = rfactorial(*argv[1]);
	printf("%d\n",num);
	return 0;
}

