#include<stdio.h>
void main()
{ int c;
	float f;
	for(c=300;c>=0;c-=20)
	{ f=(c*9/5)+32;
		printf("%d\t%d\n",c,(int)f);
	}
}

