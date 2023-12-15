#include<stdio.h>
#include<string.h>
void main()
{ char temp[1000];
	int n,c,i;
	n=0;
while((c=getchar())!=EOF)
{ if(c!='\n')
	temp[n++]=c;
 else 
 {     temp[n]='\0';
	 if(n>80)
	 {
       for(i=0;i<n;i++)
       {printf("%c",temp[i]);
       }
       printf("\n");}
       n=0;}
}
}
       
	
