#include<stdio.h>
void main()
{ int c,w,l,ch;
	w=0;
	l=0;
	ch=0;
	while((c=getchar())!=EOF)
	{
		if(c=='\n')
		l++;
	        if (c==' '||c=='\t'||c=='\n')
			w++;
		else ch++;
	}
	printf("words= %d",w);
	printf("\nlines= %d",l);
	printf("\ncharacters = %d",ch);
	
}
