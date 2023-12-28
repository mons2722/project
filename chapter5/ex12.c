#include<stdio.h>
#include<stdlib.h>

void detab(int m, int n)
{int c,count=1,pos,d,i;
 while((c =getchar())!=EOF)
 {	 if(c=='\n'||count==m)
		 count=1;
	 if (c!='\t')
	 {putchar(c);
	 count++;}
	 else{ d=count/n;
	       pos=(d+1)*n;
		while(count<=pos)
		{printf(" ");
	         count++;
		}
	 }
 }
}

void entab(int m, int n)
{
    int nb, nt, pos, c;
    nb = 0;
    nt = 0;

    for (pos = 1; (c = getchar()) != EOF; ++pos)
        if (c == ' ') {
            if ((pos % n) != 0)
                ++nb;
            else {
                nb = 0;
                ++nt;
            }
        } else {
            for (; nt > 0; --nt)
                putchar('\t');
            if (c == '\t')
                nb = 0;
            else
                for (; nb > 0; --nb)
                    putchar(' ');

            putchar(c);

            if (c == '\n'||pos==m)
                pos = 0;
            else if (c == '\t')
                pos = pos + (n- (pos - 1) % n) - 1;
        }

}

void main(int argc, char *argv[])
{
   int m,n;
   ++argv;
 //  printf("%s\n",argv[0]);
     if((*argv[0])=='-')
	  m=*argv[1]-'0';
     argv+=2;
     n=atoi(*argv);
  
   detab(m,n);
} 

