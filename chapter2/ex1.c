#include<stdio.h>
#include<limits.h>
void main()
{ printf("Ranges of floating point type using headers.\n");
printf("Range of signed char: %d to %d\n",SCHAR_MIN,SCHAR_MAX);
printf("Maximum value of unsigned char:%d\n",UCHAR_MAX);
printf("Range of signed int: %d to %d\n",INT_MIN,INT_MAX);
printf("Maximum value of unsigned int:%d\n",UINT_MAX);
printf("Range of signed short: %d to %d\n",SHRT_MIN,SHRT_MAX);
printf("Maximum value of unsigned short:%d\n",USHRT_MAX);
printf("Range of signed long: %ld to %ld\n",LONG_MIN,LONG_MAX);
printf("Maximum value of unsigned long:%ld\n",ULONG_MAX);
int min,max;
printf("\nRanges of floating point types by computation.\n");
min=-(char)((unsigned char)~0>>1)-1;
max=(char)((unsigned char)~0>>1);
printf("Range of signed char: %d to %d\n",min,max);
min=-(int)((unsigned int)~0>>1)-1;
max=(int)((unsigned int)~0>>1);
printf("Maximum value of unsigned char:%d\n",(unsigned char)~0);
printf("Range of signed int: %d to %d\n",min,max);
printf("Maximum value of unsigned int:%d\n",(unsigned int)~0);
min=-(short)((unsigned short)~0>>1)-1;
max=(short)((unsigned short)~0>>1);
printf("Range of signed short: %d to %d\n",min,max);
printf("Maximum value of unsigned short:%d\n",(unsigned short)~0);
long lmin,lmax;
lmin=-(long)((unsigned long)~0>>1)-1;
lmax=(long)((unsigned long)~0>>1);
printf("Range of signed long: %ld to %ld\n",lmin,lmax);
printf("Maximum value of unsigned long:%ld\n",(unsigned long)~0);
}


	
