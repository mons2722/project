#include<stdio.h>
#include<ctype.h>
void main()
{ int c,a[30],i;
	for(i=0;i<26;i++)
	{a[i]=0;}
	while((c=getchar())!=EOF)
	{
	for( i=65;i<=90;i++)
	{ if((int)toupper(c)==i)
	     a[i-65]++;
	     }
	     }
	for(i=0;i<26;i++)
	{ if(a[i]!=0)
		{
			printf("%c",(char)(i+65));
				printf(" ");
			int l=1;
			while(l<=a[i])
			{printf("#");l++;
			}
			printf("\n");

	     }	}
}


