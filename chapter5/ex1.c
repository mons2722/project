#include<stdio.h>
#include<ctype.h>
int getint(int *pn)
{ int c;
 while(isspace(c=getchar()))
   ;
 while(!isdigit(c)&&c!=EOF&&c!='-'&&c!='+')
 {c=getchar();}
 int sign=(c=='-')?-1:1;
 if(c=='-'||c=='+')
	 c=getchar();

 for(*pn=0;isdigit(c);c=getchar())
	 *pn = 10 * *pn+(c-'0');
 *pn*=sign;
 if(c==EOF)
 return c;
}

void main()
{ int n,arr[1000],i;
  
  for(n=0;getint(&arr[n])!=EOF;n++)
	  ;
  for(i=0;i<=n;i++)
	  printf("%d ",arr[i]);
}
