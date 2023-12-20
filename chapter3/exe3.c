#include<stdio.h>
#include<ctype.h>
void expand(char s1[10],char s2[100])
{int i,j;
	char ch;
	for(i=j=0;s1[i]!='\0';i++)
	{if(s1[i]=='-')
	{if(s1[i-1]=='\t'||s1[i-1]=='\n'||s1[i-1]==' '||i==0||s1[i+1]=='\0')
			s2[j++]='-';
			else if(s1[i+1]>=s1[i-1])
			{	ch=(char)(s1[i-1]+1);
				while(ch<=s1[i+1])
				{	s2[j++]=ch++;
				}
				i++;
			}
		  
		}
		else s2[j++]=s1[i];
	}
}
void main()
{ char s1[10],s2[100];
  printf("Enter short hand string:");
  scanf("%s",s1);
  expand(s1,s2);
  printf("Expanded String:\n%s",s2);
}
