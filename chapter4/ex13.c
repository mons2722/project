#include<stdio.h>
#include<string.h>
void reverse(char s[])
{ static int i=0;
  int n=strlen(s)-1;
	char temp;
	if(i<=n/2)
	{
	temp=s[i];
        s[i]=s[n-i];
	s[n-i]=temp;
	i++;
	reverse(s);}}
void main()
{ char s[100];
	printf("Enter a string:");
	scanf("%s",s);
	reverse(s);
	printf("Reversed string:%s",s);
}
