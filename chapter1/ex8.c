#include<stdio.h>
void main()
{int c,w,n,t;
	w=t=n=0;
while((c=getchar())!=EOF)
{ if(c=='\n')
	n++;
if (c=='\t')
	t++;
 if (c==' ')
	 w++;
}
printf("Whitespaces=%d",w);
printf("\nNewline=%d",n);
printf("\nTabs=%d",t);
}
