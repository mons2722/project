#include <stdio.h>
#include <string.h>     /*  strcpy(*s, *t)  */
#include<ctype.h>

#define MAXLINES 5000       /* max number lines to be sorted */
#define MAXSTOR 10000     /*  size of available strage space  */

char *lineptr[MAXLINES];    /* pointers to next text lines */

int readlines(char *lineptr[], char *linestor, int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int n,int f);

/*  sort input lines*/

int main (int argc, char *argv[])
{
    int nlines;             /* number of input lines to read */
    char linestor[MAXSTOR]; /* store the input lines */
   int F=0; 
     if(--argc>0 && (*argv)[0]=='-')
     { if((*argv)[1]=='f')
	     F++;
     }
	  
    nlines = readlines(lineptr, linestor, MAXLINES);
         qsort(lineptr,nlines,F);
        writelines(lineptr, nlines);
        
 
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

int charcmp(char *s, char *t)
{ for(;tolower(*s)==tolower(*t);s++,t++)
     {  if(*s=='\0')
	     return 0;
     }
     return tolower(*s)-tolower(*t);
}

void qsort(char *v[], int n, int f)
{ int i,j;
	char temp[1000];
	if(f==0)
	{for(i=0;i<n-1;i++)
         { for(j=0;j<n-1-i;j++)
            {if(strcmp(v[j],v[j+1])>0)
			 {strcpy(temp,v[j]);
    		    strcpy(v[j], v[j+1]);
   	            strcpy(v[j+1],temp);}
		 }
	 }
	}
	else  {for(i=0;i<n-1;i++)
              { for(j=0;j<n-1-i;j++)
	        { if(charcmp(v[j],v[j+1])>0)
                         {strcpy(temp,v[j]);
                    strcpy(v[j], v[j+1]);
                    strcpy(v[j+1],temp);}
                 }
         }
        }
}

