#include<stdio.h>
#include<stdlib.h>

void detab(int tab[], int n)
{int c,count=1,pos,d,i;
 while((c =getchar())!=EOF)
 {	 if(c=='\n')
		 count=1;
	 if (c!='\t')
	 {putchar(c);
	 count++;}
	 else { for(i=0;i<n;i++)
		{if(tab[i]>count)
			{pos=tab[i];
			break;}
		}
		while(count<=pos)
		{printf(" ");
	         count++;
		}
	 }
 }
}

void entab(int argc, char *argv[])
{
    int nb, nt, pos, c;
    int tab;
    nb = 0;
    nt = 0;

    for (pos = 1; (c = getchar()) != EOF; ++pos)
        if (c == ' ') {
            if ((pos % 8) != 0)
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

            if (c == '\n')
                pos = 0;
            else if (c == '\t')
                pos = pos + (8- (pos - 1) % 8) - 1;
        }

}

void sort(int a[],int n)
{ int i,j,temp;
	for(i=0;i<n-1;i++)
	{for(j=0;j<n-1-i;j++)
	{if(a[j]>a[j+1])
	 { temp=a[j];
	   a[j]=a[j+1];
           a[j+1]=temp;}}}}	   

void main(int argc, char *argv[])
{
   int sp[100];
   int i=0;
   while(--argc>0)
	   sp[i++]=atoi(*++argv);
   sort(sp,i);
   detab(sp,i);
}

