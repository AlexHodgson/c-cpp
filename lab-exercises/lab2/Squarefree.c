#include <stdio.h>
char cont = 'y';
int num;
int i;
int test;


int main(void){
	while(cont == 'y'){
		cont = ' ';
		printf("Enter a number to test if it is squarefree: ");
		scanf("%d",&num);
		i = 2; // Start at 2, as everything is divisible by 1
		while(1){
			test = i * i;
			if(test < num){ // If the squares are now bigger than the number to be tested, the loop is exited
				if(num % test == 0){
					printf("%d is not a squarefree number\n",num);
					break;
				}
			}
			else{
				printf("%d is a squarefree number\n",num);
				break;
			}
			i++;
		}
		while(cont != 'y' && cont != 'n'){ //Make sure input is valid
			printf("Continue? y/n ");
			scanf("%s",&cont); // Check if the user wants to continue
		}
	}
	
	return 0;
}

