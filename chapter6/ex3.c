#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NOICE -1
#define YES 1
#define NO 0
#define MAX 1000

struct list
{ char *word;
  int count;
  int n[100];
  struct list *next;
};

char *noice[]={"a","an","and","be","but","by","he","I","is","it","off","on","she",
    "so","the","they","you"};

struct list *head=NULL;
struct list *cur=NULL;

void addnew(char *w,int ln)
{ 
 struct list *ptr=(struct list*)malloc(sizeof(struct list));
 ptr->word=w;
 ptr->count=1;
 ptr->n[ptr->count-1]=ln;
 if(head==NULL)
 {head = ptr;
  cur=head;}
 else{ cur->next=ptr;
       cur=cur->next;
 }
}

void update(struct list *pos,int ln)
{ pos->count++;
  pos->n[pos->count-1]=ln;
}


int search(char *w,struct list *pos)
{
  int low =0,high= sizeof(noice)/sizeof(noice[0]) -1;
  int cond,mid;
  while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(w, noice[mid])) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return NOICE;
  }
  
  struct list *temp;
  if(head==NULL)
	  return NO;
  else{temp=head;
  while(temp->next!=NULL)
   {
     if(strcmp(temp->word,w)==0)
     { pos=temp;
	     return YES;}
     temp=temp->next;
   }}
 return NO;
}

int get_line(char arr[], int lim) {
    int c, i;
    for (i = 0; i < lim  && (c = getchar()) != EOF && c != '\n'; ++i) {
        arr[i] = c;
    }
    if (c == '\n')
        arr[i] = '\0';
       
        
    return i;
}

void main()
{ int n,ln=0,j,res;
  char ar[MAX];
  char word[100];
  struct list *p;
  while((n=get_line(ar,MAX))>0)
  { ln++;
	  printf("%s\n",ar);
    int i=0;
   while(ar[i]!='\0') 
    { j=0;
     while(ar[i]!=' '&& ar[i]!='\t')
	    word[j++]=ar[i++];
      word[j]='\0';
      i++;
     printf("%s\n",word);
     res=search(word,p);
     printf("%d\n",res);
     switch(res)
     { case YES: update(p,ln);
	         break;
       case NO: addnew(word,ln);
     }
    }
  }
  p=head;
  while(p->next!=NULL)
  { printf("\n%s -",p->word);
    for(int i=0;i<p->count;i++)	  
    printf("%d",p->n[i]);	  
}
     
}

