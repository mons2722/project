#include<stdio.h>
void main()
{int c,count=1,pos,d;
 while((c =getchar())!=EOF)
 {	 if(c=='\n')
		 count=1;
	 if (c!='\t')
	 {putchar(c);
	 count++;}
	 else { d=count/8;
		pos=((d+1)*8);
		while(count<=pos)
		{printf(" ");
	         count++;
		}
	 }
 }
}
