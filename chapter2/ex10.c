#include<stdio.h>
char lower(char c)
{ char ch;
	ch=(c>='A'&&c<='Z')?(char)(c+32):c;
	return ch;
}
void main()
{ char c;
	printf("Enter an upper case character:");
	scanf("%c",&c);
		printf("Lower Case of %c : %c\n",c,lower(c));
}
