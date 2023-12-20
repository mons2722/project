#include<stdio.h>
#include<ctype.h>
#include<math.h>
double atof(char s[])
	{int i;
	       	for(i=0;isspace(s[i]);i++)
	                ;
	int sign;
	float val=0.0,power=0;
		float dec=0;
	if(s[i]=='-')
	{sign=-1;
		i++;
	}
	else 
		sign=1;
	while(isdigit(s[i]))
	{ val=(val*10.0)+(s[i]-'0');
		i++;
	}// printf("%f\n",val);
	if(s[i]=='.')
	{i++;
		while(isdigit(s[i]))
		{val=(val*10.0)+(s[i]-'0');
		dec++;
			i++;
		}}//printf("%f\n",val);
                  //printf("%f\n",dec);
		val=val/pow(10,dec);
		
		//printf("%f",val);
	if(s[i]=='e'||s[i]=='E')
	{if(s[++i]=='+')
		power=(s[i+1]-'0');
         else   power=-(s[i+1]-'0');
	}
	return sign*(val*pow(10,power));
}
void main()
{ char s[100];
  printf("Enter a floating point string:");
  scanf("%s",s);
  printf("Converted to float: %lf\n",atof(s));
}
