#include<stdio.h>
#include<string.h>
void squeeze(char s1[100],char s2[100])
{ int i,j,k,flag;
	k=0;
	char st[100];
  for(i=0;s1[i]!='\0';i++)
  { flag =0;
	  for(j=0;s2[j]!='\0';j++)
	  {if(s1[i]==s2[j])
		  {flag++;
		   break;}
	  }
	  if(flag==0)
		  s1[k++]=s1[i];
  }
s1[k]='\0';
printf("S1 after deleting matching characters with S2: %s",s1);
}
void main()
{
 char s1[10],s2[10];
 printf("Enter 2 strings S1,S2:");
 scanf("%s%s",s1,s2);
 squeeze(s1,s2);
 }
