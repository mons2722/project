#include<stdio.h>
void main()
{ int c,i;
int count=0,n=0,j;
char st[200][1000];
 int p,box,br;
 p=box=br=0;
 while((c=getchar())!=EOF)
 { st[n][count]=c;
	 if(c=='\n')
	 {n++;count=0;}
	 else count++;
 }
 for(i=0;i<n;i++)
 { for(j=0;st[i][j]!='\0';j++)
	 {
		 if(st[i][j]=='(')
			p++;
		 else if(st[i][j]==')')
			 p--;
		 else if(st[i][j]=='[')
		       box++;
		  else if(st[i][j]==']')
                       box--;
                   else if(st[i][j]=='{')
                       br++;
		    else if(st[i][j]=='}')
                       br--;
           }	 puts(st[i]);
	 if(p!=0)
	 printf("//unmatched paranthesis.\n");
         if (box!=0)
		 printf("//unmatched brackets.\n"); 
p=0;
box=0;
 }
   if(br!=0)
                 printf("//unmatched Curly braces in %d places.\n",br);

}


