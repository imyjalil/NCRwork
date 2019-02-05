#include<stdio.h>
int main()
{
	int b,h=0,i=1,r;
	printf("Enter binary number:");
	scanf("%ld",&b);
	while(b>0)
	{
		r=b%10;
		h=h+r*i;
		i=i*2;
		b=b/10;
	}
	printf("Hexadecimal: %lx",h);
	return 0;
}

