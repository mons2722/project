#include<stdio.h>
unsigned rightrot(unsigned x,int n)
	{
	       int k;
       k=~(~0<<n);
       k=x&k;
       k=k<<(8*sizeof(x)-n);
       return (x >> n) | k;
}
void main()
{  int n;
	unsigned x;
      printf("Enter x:");
      scanf("%u",&x);
      printf("Enter n:");
      scanf("%d",&n);
      printf("Rotated Value of x: %u\n",rightrot(x,n));
}
