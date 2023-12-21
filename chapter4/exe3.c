#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define max 100
double stack[max];
int top=-1;
double pop()
{ //printf("pop=%d\n",stack[top]);
	return stack[top--];
	
}
void  push(double n)
{stack[++top]=n;
//printf("push=%d\n",stack[top]);
}
void main()
{
	double op;
	char ptr[10],s[100];
        printf("Expression:");
	int i=0;
	char c;
	while((c=getchar())!='\n')
        {s[i++]=c;}
	s[i]='\0';
	printf("%s",s);
        int j;
	for(j=0;s[j]!='\0';j++)
	{i=0;
		if(isspace(s[j]))
		continue;
		if(isdigit(s[j]))
		{while(isdigit(s[j]))
		  ptr[i++]=s[j++];
                ptr[i]='\0';
                 push(atof(ptr));}
		if(s[j]=='-'&&(s[j+1]!=' '))
		{ j++;
			while(isdigit(s[j]))
                           ptr[i++]=s[j++];
		     ptr[i]='\0';
		 push(-atof(ptr));}
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
		         case '%':op=pop();
                                   push(fmod(pop(),op));
                                   break;
		        }
		     }
	}
       printf("Result= %lf",stack[top]);
}

