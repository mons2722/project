#include<stdio.h>
void Strcat(char *s, char *t)
{
   while(*s!='\0')
        s++;	   

	while((*s=*t)!='\0')
	{	s++;
	        t++;
	}
}
void main()
{ char s[10],t[10];
	printf("Enter string 1:");
	
	scanf("%s",s);
	 printf("Enter string 2:");
	
        scanf("%s",t);
	Strcat(s,t);
	printf("Concatenated String:%s \n",s);
}
