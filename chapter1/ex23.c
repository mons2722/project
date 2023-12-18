#include<stdio.h>
void main()
{ int c;
	while((c=getchar())!=EOF)
	{if(c=='/')
		{ if((c=getchar())=='/')
			{while((c=getchar())!='\n')
						;
				putchar(c);		}
			else if(c=='*')
			{ while((c=getchar())!='/')
			  ;
			  }
			  else {putchar('/');
			  putchar(c);}
		}
			  else 
			  putchar(c);
			 }}
