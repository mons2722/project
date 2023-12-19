#include<stdio.h>
#include<ctype.h>
void expand(char s1[10],char s2[100])
{int i,j;
	char ch;
	for(i=j=0;s1[i]!='\0';i++)
	{if(s1[i]=='-')
		{if(s1[i+1]==(s1[i-1]+1))
			{s2[j++]=s1[i+1];
				i++;}
	          else	if(isalpha(s1[i-1])&&isalpha(s1[i+1]))
			{i++;
				for(ch=(char)(s1[i-1]+1);ch<=s1[i+1];ch++)
					s2[j++]=ch;
			}
		  else if(isdigit(s1[i-1])&&isdigit(s1[i+1]))
		  {i++;
                        for(ch=(char)(s1[i-1]+1);ch<=s1[i+1];ch++)
                            s2[j++]=ch;
                        } 
		  else 
			s2[j++]='-';
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
