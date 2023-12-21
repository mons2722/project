#include<stdio.h>
#include<stdlib.h>
#define max 100
int stack[max];
int top=-1;
int pop()
{ if(top==-1)
    printf("Stack empty!\n");
    else 
    { printf("Element Deleted!\n");
	    return stack[top--];
    }
}
void  push(int n)
{if(top==max-1)
	printf("Stack Overflow!\n");
else { 	stack[++top]=n;
printf("Element %d added! \n",stack[top]);
}
}
void showtop()
{if(top==-1)
    printf("Stack empty!\n");
    else 
     printf("Top element= %d\n", stack[top]);
}
void dup()
{ if(top==-1)
    printf("Stack empty!\n");
    else
    { 	    stack[++top]=stack[top];
	    printf("Duplicated Top element= %d\n", stack[top]);
    }
}
void swap()
{if(top==-1)
    printf("Stack empty!\n");
    else
    {    int temp;
	    temp=stack[top];
        stack[top]=stack[top-1];
	stack[top-1]=temp;
            printf("Swapped succesfully!\n");
    }
}
void clr()
{  	top=-1;
  printf("Stack Cleared!");
}
void disp()
{ if(top==-1)
    printf("Stack empty!\n");
    else
    { int i;
	    for(i=top;i>=0;i--)
	    {printf("%d\n",stack[i]);
	    }
    }
}
void main()
{int c;
 char ch;
 do{
     printf("Program Menu for Stack operations");
     printf("\n1.push");
     printf("\n2.pop");
     printf("\n3.display stack");
     printf("\n4.print top element");
     printf("\n5.swap top 2 elements");
     printf("\n6.duplicate top element");
     printf("\n7.clear stack");
     printf("\n8.exit");
     printf("\nEnter your choice:");
     scanf("%d",&c);
     getchar();
     switch(c)
     { case 1: printf("Enter element to push:");
	       int ele;
	       scanf("%d",&ele);
	       getchar();
	       push(ele);
	       break;
       case 2: pop();
	       break;
       case 3: disp();
	       break;
       case 4: showtop();
	       break;
       case 5: swap();
	       break;
       case 6: dup();
	       break;
       case 7: clr();
	       break;
       case 8: exit(0);
       default:printf("Invalid Input:");
     }
     printf("Do you want to continue?(y/n):");
     scanf("%c",&ch);
 } while(ch=='y' || ch == 'Y');
 }
	      



