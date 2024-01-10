#include<stdio.h>
#include<stdlib.h>

void *Calloc(int n, int size)
{
 int *p,*q;
 unsigned nb=n*size;

 if((p=q=malloc(nb))!=NULL)
 {for(int i=0;i<nb;i++)
	 *p++=0;
 }
 return q;
}

void main()
{ 
 unsigned n;
 unsigned *p=NULL;
 
 printf("Enter no. of elements:");
 scanf("%d",&n);
 p=(unsigned *)Calloc(n,sizeof(*p));
 if(p==NULL)
 printf("No memory allocated!!");
 else
 { for(int i=0;i<n;i++)
	 printf("%08x ",p[i]);
 }
 free(p);
}
	
