#include<stdio.h>
#include<string.h>
void main()
{ char st[1000];
	int n;
	FILE *f=fopen("f.txt","r");
	while((n=getline(st,1000,f))>0)
	{ if(n>80)
		printf("%s",st);
	}
}

