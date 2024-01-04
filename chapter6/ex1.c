#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct keyword
{   char *word;
	int count;
}key[] = {"auto", 0, "break", 0, "case", 0, "char", 0,
              "const", 0, "continue", 0, "default", 0, "do", 0,
              "double", 0, "else", 0, "enum", 0, "extern", 0,
              "float", 0, "for", 0, "goto", 0, "if", 0,
              "int", 0, "long", 0, "register", 0, "return", 0,
              "short", 0, "signed", 0, "sizeof", 0, "static", 0,
              "struct", 0, "switch", 0, "typedef", 0, "union", 0,
              "unsigned", 0, "void", 0, "volatite", 0, "while", 0};

#define N (sizeof(key)/sizeof(key[0]))
#define MAX 100
int getword(char *word, int lim)
{ int c;
  char *w;
  c=getchar();
    while(isspace(c))
	  c=getchar();
    if(!isalpha(c))
    {  if(c=='#')
    {while((c=getchar())!='\n')
	     ;    }
    else if((c=getchar())=='\"')
    {while((c=getchar())!='\"')
             ;    }
    else if((c=getchar())=='/')
    { if((c=getchar())=='*')
	    {   while((c=getchar())!='*'&&(c=getchar())=='/')
		    ; }
      else { while((c=getchar())!='\n')
		      ;  }      }
      return c;
      }
      else
          { while(c!='\n'||c!=EOF||c!=' '||c!='\t')
	      { *w++=c;
	         c=getchar();}}
	      *w='\0';
	      return c;
	      }
     
 int binsearch(char *word, struct keyword key[], int n) 
 {
    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, key[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}     
void main()
{
 int c,n;
 char *w;
 while((c=getword(w,MAX))!=EOF)
 { if(isalpha(w[0]))
    {if(n=binsearch(w,key,N)!=-1)
	    key[n].count++;
    }
 }

 for(int i=0;i<N;i++)
 { printf("%s - %d\n",key[i].word,key[i].count);
 }
}
   
