#include<stdio.h>
void main()
{
	int c,d,pos,count=0,start;
        while((c=getchar())!=EOF)
	{ if (c!=' ')
		{putchar(c);
		count++;
		}
		else { start=count;
			while((c=getchar())==' ')
			{ count++;}
			d=count-start;
			if(d>1)
			{
			pos=d/8;
			int i=0;
			while(i<=pos+1)


			
