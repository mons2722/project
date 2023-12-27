#include <stdio.h>
#include <string.h>     /*  strcpy(*s, *t)  */

#define MAXLINES 5000       /* max number lines to be sorted */
#define MAXSTOR 10000       /*  size of available strage space  */

char *lineptr[MAXLINES];    /* pointers to next text lines */

int readlines(char *lineptr[], char *linestor, int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int n);

/*  sort input lines*/

int main (void)
{
    int nlines;             /* number of input lines to read */
    char linestor[MAXSTOR]; /* store the input lines */
    
    if((nlines = readlines(lineptr, linestor, MAXLINES)) >= 0)
    {
        qsort(lineptr,nlines);
        writelines(lineptr, nlines);
        
        return 0;
    }
    else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLINE 1000        /*  maximum length of line    */

char *alloc(int);
int getline3(char *s, int lim);
void strcpy1(char *s, char *t);

/*  read input lines    */
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
    printf("nlines:%d\n", nlines);
    return nlines;
}

#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    if(ALLOCSIZE + allocbuf >= n + allocp)
    {
        allocp += n;
        return allocp - n;
    }
    else
        return 0;
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
void writelines(char *lineptr[], int nlines)
{
    while(nlines-- >0)
        printf("%s\n", *lineptr++);
}


void qsort(char *v[], int n)
{ int i,j;
	char temp[1000];
	for(i=0;i<n-1;i++)
         { for(j=0;j<n-1-i;j++)
		 {if(strcmp(v[j],v[j+1])>0)
			 {strcpy(temp,v[j]);
    		    strcpy(v[j], v[j+1]);
   	            strcpy(v[j+1],temp);}
	 }}
}
