#include<stdio.h>
#include<ctype.h>
int getfloat(float *pn)
{ int c,d=1;
 while(isspace(c=getchar()))
   ;
 while(!isdigit(c)&&c!=EOF&&c!='-'&&c!='+')
 {c=getchar();}
 int sign=(c=='-')?-1:1;
 if(c=='-'||c=='+')
	 c=getchar();

 for(*pn=0;isdigit(c);c=getchar())
	 *pn = 10 * *pn+(c-'0');
 if(c=='.')
 { for(;isdigit(c=getchar());)
	 {*pn = 10 * *pn+(c-'0');
	    d*=10;}}
 *pn=(*pn)/d;	 
 *pn*=sign;
 if(c==EOF)
 return c;
}

void main()
{ float arr[1000];
	int n,i;
  
  for(n=0;getfloat(&arr[n])!=EOF;n++)
	  ;
  for(i=0;i<=n;i++)
	  printf("%.4f ",arr[i]);
}
