#include<stdio.h>
#include<stdlib.h>
void Strncpy(char *s,char *t,int n)
{ int count=1;
	while((*s++=*t++)!='\0'&&count<=n)
		count++;
}
void Strncat(char *s,char *t,int n)
{ int count=1;
	while(*s!='\0')
        s++;	   

	while((*s=*t)!='\0'&&count<=n)
	{	s++;
	        t++;
		count++;
	}
}
int Strncmp(char *s,char *t, int n)
{ int count=1;
	while((*s==*t)&&count<=n)
	{s++,t++;
		if(*s=='\0')
		return 0;
	}
	return *s - *t;
}
void main()
{
  int n,c,d;
  char s[100],t[100],ch;
  printf("Enter two strings:");
  scanf("%s %s",s,t);
  printf("Enter n:");
  scanf("%d",&n);
do{  printf("\n1.Stringcopy");
  printf("\n2.String concatenate");
  printf("\n3.String compare");
  printf("\n4.Exit");
  printf("\nEnter your choice:");
  scanf("%d",&c);
  switch(c)
  { case 1: Strncpy(s,t,n);
	    printf("String 1:%s",s);
	    break;
    case 2: Strncat(s,t,n);
	    printf("Concatenated string:%s",s);
	    break;
    case 3: d=Strncmp(s,t,n);
	   // printf("%d\n",d);
	    if(d==0)
	      printf("Strings are equal");
	    else 
		if(d>0)
	      printf("String 1 is greater than string 2");
	    else
	      printf("String 1 is lesser than string 2");
		    break;
    case 4: exit(0);
  }getchar();
 printf("\nDo you want to continue(y/n)?");
 scanf("%c",&ch);
}while(ch=='y'||ch=='Y');
}
