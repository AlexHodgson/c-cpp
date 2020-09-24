#include <stdio.h>

int main(void) {
	
	int i,*myPtr , **myPtrPtr;
	int a[2] = {1,2};
	printf("%p\n",a); //a holds a memory address of the start of the array, so printing a gives the memory location
	
	i = 6;
	myPtr = &i;
	myPtrPtr = &myPtr;
	{
		int i = 7;
		myPtr = 45;
		printf("The value %d is stored in location %p\n",myPtr ,&myPtr); //Prints the current value of myPtr, 45, and the memory location where it is stored
		printf("The value %d is stored in location %p\n", i, &i); //Prints the current value of i, and it's memory location
	}
	
	printf("The value %p is stored in the location %p\n",myPtrPtr , &myPtrPtr);
	printf("The value %d is stored in location %p\n", i, &i);

return 0;
}
