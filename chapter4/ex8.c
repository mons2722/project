#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#define max 100
double stack[max];
int top=-1;
int buf = EOF; /* buffer for ungetch */

int getch(void) /* get a (possibly pushed back) character */
{
  int temp;

  if (buf != EOF) {
    temp = buf;
    buf = EOF;
  } else {
    temp = getchar();
  }
  return temp;
}

void ungetch(int c) /* push character back on input */
{
  if(buf != EOF)
    printf("ungetch: too many characters\n");
  else
    buf = c;
}
double pop()
{ //printf("pop=%d\n",stack[top]);
	return stack[top--];

}
void  push(double n)
{stack[++top]=n;
//printf("push=%d\n",stack[top]);
}
void ungets(char s[])
{ printf("%s",s);}
void main()
{
	double op;
	char ptr[10],s[100];
        printf("Expression:");
	int i=0;
	char ch[10];
	char c;
	double buf[26];
	while((c=getchar())!='\n')
        {s[i++]=c;}
	s[i]='\0';
	printf("%s",s);
	 int j=0,count=0;
         while(j<=strlen(s)-1)
	 {if(isdigit(s[j++]))
		 {count++;
			 break;}}
	 if(count==0)
		 ungets(s);
	 else {
	 for(j=0;s[j]!='\0';j++)
	{i=0;
		if(isspace(s[j]))
		continue;
		if(isdigit(s[j]))
		{while(isdigit(s[j]))
		  ptr[i++]=s[j++];
                ptr[i]='\0';
                 push(atof(ptr));}
		else if(isalpha(s[j]))
		{ if(s[j+1]==' ')
                  {   c=s[j];
                          j++;
                          if(s[j+1]=='=')
                            buf[c-'A']=pop();
                            else push(buf[c-'A']);}
                  else{	
	  	  while(isalpha(s[j]))
		  ch[i++]=s[j++];
		  ch[i]=='\0';
		  if((strcmp(ch,"pow")==0))
			  {op=pop();
			  push(pow(pop(),op));
			  }
		  else if((strcmp(ch,"sin")==0))
		          push(sin(pop()));
		  else if((strcmp(ch,"exp")==0))
			  push(exp(pop()));
		  else printf("\nInvalid operator");}}

		  if(s[j]=='-'&&(s[j+1]!=' '))
		{ j++;
			while(isdigit(s[j]))
                           ptr[i++]=s[j++];
		     ptr[i]='\0';
		 push(-atof(ptr));}
	        else{
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
       printf("\nv= %.4lf",stack[top]);
	 }}
