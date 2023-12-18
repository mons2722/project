#include<stdio.h>
int any(char s1[10],char s2[10])
{ int pos=-1,i,j;
	for(i=0;s1[i]!='\0';i++)
	{ for(j=0;s2[j]!='\0';j++)
		{if(s1[i]==s2[j])
			{pos=i;
			break;
			}
		}
	}
	if(pos!=-1)
		return pos+1;
	else 
		return pos;
}
void main()
{
  char s1[10],s2[10];
  printf("Enter 2 strings S1,S2:");
  scanf("%s%s",s1,s2);
  int n=any(s1,s2);
  if(n==-1)
	  printf("There are no characters in S1 matching S2");
  else 
	  printf("Position of the first matching character in S1 with S2 : %d",n);
}
