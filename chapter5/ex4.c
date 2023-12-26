#include<stdio.h>
#include<string.h>
int strend(char *s,char *t)
{ int count=0,n;
   n=strlen(t);
  while(*s++!='\0')
	  ;
  while(*t++!='\0')
          ;
  s--;t--;
  while(*s--==*t--)
  {  count++;}
 
    count--;
 
  if(count==n)
	  return 1;
  else 
	  return 0;
}
void main()
{ char s[10],t[10];
	printf("Enter string 1:");
	scanf("%s",s);
	printf("Enter string 2:");
        scanf("%s",t);

  int c=strend(s,t);
  printf("IS S2 at the end of S1? ");
	  if(c==1)
		  printf("yes");
	  else 
		  printf("No");
}
