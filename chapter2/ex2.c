#include<stdio.h>
void main()
{int c;
	char s[1000];
	int lim=100;
	int i;
       printf("Result for loop using && and ||:\n");
	for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
       s[i] = c;
	printf("%s",s);
	 char st[1000];
	for(i=0;i<lim-1;i++)
	{
	 c=getchar();
		if(c=='\n')
			break;
		if(c==EOF)
			break;
		st[i]=c;
	}
	printf("\nResult for loop without using && and ||:\n");
	printf("%s",st);
}
	
