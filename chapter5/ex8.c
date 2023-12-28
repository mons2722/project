#include<stdio.h>
#include<stdlib.h>

static int days[2][12]={{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int y, int m, int d)
{ int leap,i,yd=0;
	leap=((y%4==0&&y%100!=0)||y%400==0);
	//error checking
	if(y<1||m<1||m>12||d>days[leap][m-1])
		return -1;
	for(i=0;i<m-1;i++)
	{yd+=days[leap][i];}
	yd+=d;
	return yd;
}

void month_day(int y, int yd, int *pm, int *d)
{ int leap,i;
	leap=((y%4==0&&y%100!=0)||y%400==0);
        //error checking
        if(y<1||yd>(leap?366:365))
	{ *pm=-1;
	  *d=-1;}
       for(i=0;yd>days[leap][i];i++)
       { yd-=days[leap][i];}
       *pm=i+1;
       *d=yd;
}

void main()
{
	int c,d,m,y;
	int yd;
	char ch;
	do{
		printf("\n1.Day of year");
		printf("\n2.Day of Month");
		printf("\n3.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&c);
		switch(c)
		{ case 1:printf("Enter date,month and year");
			 scanf("%d %d %d",&d,&m,&y);
			 yd=day_of_year(y,m,d);
                         printf("\nDay of year:%d",yd);
			 break;
	          case 2:printf("Enter day, year:");
			 scanf("%d %d",&yd,&y);
                         month_day(y,yd,&m,&d);
                         printf("\nmonth:%d",m);
			 printf("\nDay of month:%d",d);
			 break;
		  case 3:exit(0);
	          default:printf("Wrong Choice");
		}
		getchar();
		printf("Do you want to continue(y/n)?");
		ch=getchar();
	}while(ch=='y'||ch=='Y');
}
