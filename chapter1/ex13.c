#include<stdio.h>
void main()
{
	int c,len=0,i;
	while((c=getchar())!=EOF)
	{ len++;
		if(c==' '||c=='\t'||c=='\n')
		{ for(i=1;i<len;i++)
			printf("#");
			printf("\n");
			len=0;
		}
	}
}
