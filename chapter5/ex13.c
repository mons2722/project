#include <stdio.h>
#include <string.h>     /*  strcpy(*s, *t)  */

#define MAXLINES 5000       /* max number lines to be sorted */
#define MAXSTOR 10000      
#define MAXLINE 1000  /*  size of available strage space  */

char *lineptr[MAXLINES];    

int getline3(char *s, int lim)
{
    int c;
    char *p;
    p = s;
    while (--lim >0 && (c = getchar())!=EOF && c!='\n') {
        *s++ = c;
    }
    if(c == '\n')
        *s++ = c;
    *s = '\0';
    return (int)(s - p);
}

int readlines(char *lineptr[], char *linestor, int maxline)
{
    int len, nlines;
    nlines = 0;
    char line[MAXLINE];
    char *p = linestor;
    char *linestop = linestor + MAXSTOR;
    
    
    while ((len = getline3(line, MAXLINE)) > 2) {
        if (nlines >= MAXLINES || (p + len > linestop)){
            return -1;
        }
        
        else
        {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }
   
    return nlines;
}

/*  writelines: write output lines*/
void writelines(char *lineptr[], int nlines,int pos)
{
  int i=0;
  while(i++<pos)
	  *lineptr++;
 while(pos++<nlines)
	printf("%s\n",*lineptr++); 
        
}


void main (int argc, char *argv[])
{
    int nlines;             /* number of input lines to read */
    char linestor[MAXSTOR]; /* store the input lines */
    int count=10;
    if (argc!=1)
    {++argv;
    if((*argv)[0]=='-')
        count=(*argv)[1]-'0';}
    nlines = readlines(lineptr, linestor, MAXLINES);
   int pos= nlines-count;
    writelines(lineptr,nlines,pos);
}


