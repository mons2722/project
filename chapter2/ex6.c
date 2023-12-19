#include<stdio.h>
int setbits(unsigned x,int p, int n, unsigned y)
{ return (x&~(~(~0<<n)<<(p+1-n)))|(y&(~(~0<<n))<<(p+1-n));
}
void main()
{ printf("%d",setbits((unsigned)0,4,3,(unsigned)~0));
	
}	
