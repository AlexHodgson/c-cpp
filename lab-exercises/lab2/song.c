#include <stdio.h>

int main(void)
{
	
	int i = 1;
	int bottles;
	
	printf("Enter number of bottles to begin: ");
	scanf("%d",&bottles);
	
	for(i = bottles; i > 1 ; i--){
		printf("%d Green bottles, sitting on the wall \n%d Green bottles, sitting on the wall\n",i,i);
		printf("And if 1 green bottle should accidentally fall\nThere'd be %d green bottles, sitting on the wall\n",(i-1));
		
	}
	printf("%d Green bottle, sitting on the wall \n%d Green bottle, sitting on the wall\n",i,i);
	printf("And if 1 green bottle should accidentally fall\nThere'd be no green bottles, sitting on the wall\n");
	
	return 0;
}

