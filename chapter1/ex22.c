#include<stdio.h>
void main()
{int c,pos=0,n=20;
while((c=getchar())!=EOF)
{ pos++;
	putchar(c);
	if(pos==n)
	{ printf("\n");
           c=getchar();
	   while(c==' '||c=='\t')
	   {c=getchar();}
	   putchar(c);
	}
	if(c=='\n')
		pos=0;
}
}



