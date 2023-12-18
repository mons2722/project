#include<stdio.h>
int htoi(const char st[100])
{ int n=0,hex;
	int i=0;
	if(st[i]=='0')
	{ i++;
		if(st[i]=='X'||st[i]=='x')
		   i++;
	}
	
	for(;st[i]!='\0';i++)
	{if(st[i]>='0'&&st[i]<='9')
		hex=st[i]-'0';
	else if(st[i]>='A'&&st[i]<='F')
		hex=st[i]-'A'+10;
	else if(st[i]>='a'&&st[i]<='f')
		hex=st[i]-'a'+10;
	n=n*16+hex;}
	return n;
}
void main()
{ int c,n;
	char st[100];
	printf("Hexadecimal string:");
	scanf("%s",st);
	  n=htoi(st);
	printf("\nHexadecimal converted to integer:%d",n);
}
