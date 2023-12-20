#include<stdio.h>
#include<string.h>
void reverse(char s[100])
{int n=strlen(s);
 int i;
 char temp;
 for(i=0;i<n/2;i++)
 {temp=s[i],s[i]=s[n-1-i],s[n-1-i]=temp;}}
void itob(int n,char str[100],int b)
{
	int s=n;
	if(n<0)
	n=-n;
	int r,i=0;
  while(n!=0)
  {r=n%b;
	  if(r<=9)
	  str[i++]=(char)(r+'0');
	  else
		  str[i++]=(char)(r-10+'A');
	  n=n/b;
  }
  if(s<0)
	  str[i++]='-';
  str[i]='\0';
  reverse(str);
}
void main()
{int n,b;
	char st[100];
	printf("Enter a number:");
	scanf("%d",&n);
	printf("Enter base value:");
	scanf("%d",&b);
	itob(n,st,b);
        printf("Coverted integer to base value %d = %s\n",b,st);
}
