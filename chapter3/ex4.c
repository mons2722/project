#include<stdio.h>
#include<string.h>
#define abs(x) ((x<0)?-x:x) 
void reverse(char s[100])
{int n=strlen(s);
 int i;
 char temp;
 for(i=0;i<n/2;i++)
 {temp=s[i],s[i]=s[n-1-i],s[n-1-i]=temp;}}
void itoa(int n,char s[100])
{ int d=n;
	int i=0;
	do{ s[i++]=(abs(d)%10)+'0';
	}while((d=d/10)!=0);
	
  if(n<0)
   s[i++]='-';
	s[i]='\0';
  reverse(s);
}
void main()
{int n;
 char s[100];
 printf("Enter an integer:");
 scanf("%d",&n);
 itoa(n,s);
 printf("Converted integer to string:%s\n",s);
}


