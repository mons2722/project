#include<stdio.h>
#include<ctype.h>

#define MAX 100
#define OL 6

void main()
{ 
 int c,pos=0;
 while((c=getchar())!=EOF)
 { if(iscntrl(c)||isspace(c))
    {
	    if(pos+OL<=MAX)
	      pos+=OL;
	    else {pos=OL;
		  putchar('\n');
	         }
	     printf("\\%03o",c);
            if(c=='\n')
	    { pos=0;
	     putchar('\n');
	    }
    }
    else
    { if(++pos>=MAX)
	pos=0;
     putchar(c);
    }
 }
}
         	     
   
