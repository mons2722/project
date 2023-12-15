#include<stdio.h>
int convert(int f)
{
	int c;
	c=5*(f-32)/9;
	return c;
}
void main()
{ int f,c;
printf("Farenheit\tCelcius");
printf("\n%d\t\t%d",1,convert(1));
	for(f=20;f<=300;f+=20)
	{printf("\n%d\t\t%d",f,convert(f));}
}

