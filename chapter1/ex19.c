#include<stdio.h>
#include<string.h>
void reverse(char str[1000])
{ int n = strlen(str);
  int i;
  char temp;
  for(i=0;i<n/2;i++)
  {temp=str[i];
   str[i]=str[n-1-i];
   str[n-1-i]=temp;
  }
}
void main()
{ int c,n,i;
 char str[10][1000];
 n=0;i=0;
 while((c=getchar())!=EOF)
{ 
if(c=='\n')
{reverse(str[n]);
printf("\n%s",str[n]);
n++;
i=0;
}
else {str[n][i]=c;
	i++;}}}
  
