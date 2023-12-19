#include<stdio.h>
int binsearch(int a[100],int n, int c)
{ int mid,l=0,h=n-1;
  mid=(l+h)/2;
  while(l<=h&&c!=a[mid])
  { if(c>a[mid])
	  l=mid+1;
	  else h=mid-1;
	  mid=(l+h)/2;
  }
  if(c==a[mid])
	  return mid;
  else return -1;
}
void main()
{ int a[100],x,n,i,pos;
 printf("Enter the size of array:");
 scanf("%d",&n);
 printf("Enter the array:");
 for(i=0;i<n;i++)
 { scanf("%d",&a[i]);
 }
 printf("Enter element to be searched:");
 scanf("%d",&x);
 pos=binsearch(a,n,x);
 if(pos!=-1)
	 printf("Element found at position %d\n",pos+1);
 else 
	 printf("Element not found.");
}
