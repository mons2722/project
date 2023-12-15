#include<stdio.h>
void main()
{int c,count=0,pos,d;
 while((c =getchar())!=EOF)
 {	 if(c=='\n')
		 count=0;
	 if (c!='\t')
	 {putchar(c);
	 count++;}
	 else { d=count/8;
		pos=((d+1)*8)-1;
		while(count<=pos)
		{printf(" ");
	         count++;
		}
	 }
 }
}
