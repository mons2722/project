#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define max 100

int stack[max];
int top=-1;

int pop()
{ //printf("pop=%d\n",stack[top]);
	return stack[top--];
	
}

void  push(int n)
{stack[++top]=n;
//printf("push=%d\n",stack[top]);
}

void main(int argc, char *argv[])
{
	int op;
	char ptr[10];
        int i,j;
	char c, s[max];
	while(--argc>0)
        { strcpy(s,*++argv);
		printf("%s\n",s);
	   i=j=0;
		if(isspace(s[j]))
		continue;
		if(isdigit(s[j]))
		{while(isdigit(s[j]))
		  ptr[i++]=s[j++];
                ptr[i]='\0';
                 push(atoi(ptr));}
		if(s[j]=='-'&&(s[j+1]!=' '))
		{ j++;
			while(isdigit(s[j]))
                           ptr[i++]=s[j++];
		     ptr[i]='\0';
		 push(-atoi(ptr));}
	        else 
		{
		switch(s[j])
		        { case '+':push(pop()+pop());
			            break;
			  case '-':op=pop();
		                   push(pop()-op);
		                   break;
		          case '*':push(pop()*pop());
		                   break;
		          case '/':op=pop();
		                   push(pop()/op);
		                   break;
		        }
		     }
	}
       printf("Result= %d",stack[top]);
}

