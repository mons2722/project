#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define max 1000
#define abs(x) ((x<0)?-x:x) 
#define NUMBER '0'
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
/* buffer for ungetch */
/* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
/* push character back on input */
{
if (bufp >= BUFSIZE)
printf("ungetch: too many characters\n");
else
buf[bufp++] = c;
}

int Getline(char *s, int lim)
{
int c;
char *t=s;
while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
*s++ = c;
if (c == '\n')
*s++ = c;
*s = '\0';
return s-t;
}

void reverse(char *s)
{int n=strlen(s);
 int i;
 char temp;
 char *beg,*end;
 beg=s;
 end=s+n-1;
 for(i=0;i<n/2;i++)
 { temp=*beg;
   *beg=*end;
   *end=temp;
   end--;
   beg++;
 }
}

void itoa(int n,char *s)
{ int d=n;
	char *t=s;
        do{ *s++ = (abs(d)%10)+'0';
        }while((d=d/10)!=0);

  if(n<0)
   *s++ ='-';
        *s='\0';
  reverse(t);
}

int Atoi(char *s)
{
int i, n;
n = 0;
for (i = 0; *s >= '0' && *s <= '9'; ++i,s++)
{n = 10 * n + (*s - '0');
}
return n;
}

int stringindex(char *s, char *t)
{ int i,j,k;
int n=strlen(s);
int len=strlen(t);
	for(i=0;i<n;i++)
	{k=0;j=i;
		while(s[j]==t[k]&&t[k]!='\0')
		{j++;k++;}

	 if(k==len)
	  return i+1;
	 }
	return -1;
}

int getop(char *s)
{
int i, c;
while ((*s = c = getch()) == ' ' || c == '\t')
;
*(++s) = '\0';
if (!isdigit(c) && c != '.')
return c;
/* not a number */
i = 0;
if (isdigit(c))
/* collect integer part */
while (isdigit(*(++s) = c = getch()))
;
if (c == '.')
/* collect fraction part */
while (isdigit(*++s= c = getch()))
;
*s = '\0';
if (c != EOF)
ungetch(c);
return NUMBER;
}

void main()
{
	char s[max],t[max];
        int c;
        char ch;
        do{
	    printf("\n1.getline");
            printf("\n2.atoi");
            printf("\n3.itoa");
            printf("\n4.reverse");
            printf("\n5.string index");
            printf("\n6.getop");
            printf("\n7.exit");
            printf("\nEnter your choice:");
            scanf("%d",&c);
            switch(c)
	   { 
             case 1: while(Getline(s,max)>0)
	             printf("%s",s);
                     break;
	     case 2: printf("\nEnter a string:");
	             scanf("%s",s);
		     printf("String converted to int:%d",Atoi(s));
		     break;
	     case 3: printf("\nEnter a no:");
		     scanf("%d",&c);
		     itoa(c,s);
		     printf("integer converted to string:%s",s);
                     break;
	     case 4:printf("\nEnter a string:");
                     scanf("%s",s);
		    reverse(s);
                     printf("Reversed String:%s\n",s);
                     break;
	     case 5: printf("\nEnter a string:");
                     scanf("%s",s);
		     printf("Enter string to be searched:");
		     scanf("%s",t);
                      c=stringindex(s,t);
		      if(c!=-1)
                     printf("Position of string s2 in s1:%d\n",c);
		      else 
			      printf("Element not found!!");
                     break;
	    case 6: getop(s);
		    break;
            case 7: exit(0);
		    break;
	   }getchar();
 printf("\nDo you want to continue(y/n)?");
 scanf("%c",&ch);
}while(ch=='y'||ch=='Y');
}
	

	     


