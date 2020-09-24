#include <stdio.h> 
int i = 5;
int j = 2;
float ans;

int main(){
	{
	ans  = i + j;
	printf("i + j is %d\n",(int)ans);
}
{	
	ans = i - j;
	printf("i - j is %d\n",(int)ans);
}
{
	ans = i * j;
	printf("i * j is %d\n",(int)ans);
}
{
	ans = (float) i / j;
	printf("i / j is %3.2f\n",ans);
}
{
	ans = i % j;
	printf("i / j is %d\n",(int)ans);
}
return 0;
}
