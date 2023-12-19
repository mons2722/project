#include<stdio.h>
void rtoe(char s[1000],char t[1000])
{ int i,j;
  for(int i=j=0;t[i]!='\0';i++)
  { if(t[i]=='\n')
	  {s[j++]='\\';
	  s[j]='n';
	  }
	  else if(t[i]=='\t')
	  {s[j++]='\\';
          s[j]='t';
          }
	  else s[j]=t[i];
	  j++;
  }
}
void etor(char s[1000], char t[1000])
{ int i,j;
  for(i=j=0;t[i]!='\0';i++)
  {if(t[i]=='\\')
	  {i++;
	   if (t[i]=='n')
		   s[j]='\n';
	   else if(t[i]=='t')
		   s[j]='\t';
	   else s[j]='\\';
	  }
    else s[j]=t[i];
    j++;
  }
}
void main()
{
char t[1000],s1[1000],s2[1000];
int c,i=0;
while((c=getchar())!=EOF)
{t[i++]=c;}
rtoe(s1,t);
printf("Real time to escape representation:\n");
puts(s1);
etor(s2,s1);
printf("Escape representation to Real time:\n");
puts(s2);
}
