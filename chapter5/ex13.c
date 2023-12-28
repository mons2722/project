#include <stdio.h>
#include <string.h>     /*  strcpy(*s, *t)  */

#define MAXLINES 5000       /* max number lines to be sorted */
#define MAXSTOR 10000      
#define MAXLINE 1000  /*  size of available strage space  */

char *lineptr[MAXLINES];    

int readlines(char *lineptr[], char *linestor, int MAXLINE)
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
    printf("nlines:%d\n", nlines);
    return nlines;
}

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

/*  writelines: write output lines*/
void writelines(char *lineptr[], int nlines,int pos)
{
    while(nlines-- >0)
        printf("%s\n", *lineptr++);
}

int tail(char *lineptr[],int n)
{

void main ()
{
    int nlines;             /* number of input lines to read */
    char linestor[MAXSTOR]; /* store the input lines */

    nlines = readlines(lineptr, linestor, MAXLINES);
    int pos= tail(lineptr,nlines);

}


