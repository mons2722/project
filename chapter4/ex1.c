#include<stdio.h>
#include<string.h>
int stringindex(char s[], char t[])
{ int i,j,k;
int n=strlen(s);
int len=strlen(t);
	for(i=n-1;i>=0;i--)
	{k=0;j=i;
		while(s[j]==t[k]&&t[k]!='\0')
		{j++;k++;}	
		
	 if(k==len)
	  return i+1;
	 }
	return -1;
}
void main()
{ int c;
  char st[100],t[100];
  printf("Enter the line:");
  scanf("%s",st);
  printf("Enter the string to be searched:");
  scanf("%s",t);
  int pos=stringindex(st,t);
  if(pos==-1)
  printf("String not found!!");
  else 
	  printf("String found in position %d",pos);
}

