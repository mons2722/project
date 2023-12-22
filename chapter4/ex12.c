#include<stdio.h>
void itoa(int n,char s[])
{
	static int i=0;
if (n < 0) {
s[i++]='-';
n = -n;
}
if (n / 10)
itoa(n / 10,s);
s[i++]=(n % 10 + '0');
}
void main()
{
	int n;
	char s[100];
	printf("Enter a number:");
	scanf("%d",&n);
	itoa(n,s);
        printf("String:%s",s);
}
