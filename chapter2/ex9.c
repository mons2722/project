#include<stdio.h>
int bitcount(unsigned x)
{ int b;
	for(b=0;x!=0;x&=(x-1))
	{b++;}
	return b;
}
void main()
{ unsigned x;
	printf("Enter x:");
	scanf("%u",&x);
	printf("Bit count of x: %d",bitcount(x));
}
