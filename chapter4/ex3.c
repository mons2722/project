#include<stdio.h>
#define max 100
int stack[max];
int top=-1;
int pop()
{ return stack[top--];
}
void push(int n)
{stack[++top]=n;}
void main()
{
	char s[100],op[100];
        printf("Expression:\n");

