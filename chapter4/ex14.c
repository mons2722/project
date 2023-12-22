#include<stdio.h>
#define swap(t,x,y) { t a; a=x,x=y,y=a;}

void main()
{ int x,y;
	printf("x=");
	scanf("%d",&x);
	printf("y=");
	scanf("%d",&y);
	swap(int,x,y);
	printf("After swapping: x=%d\ty=%d\n",x,y);
}
