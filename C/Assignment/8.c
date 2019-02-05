#include<stdio.h>
int main()
{
	printf("Enter Basic: ");
	int bas,hra,da;scanf("%d",&bas);
	if(bas>=1 && bas<=4000)
	{
		hra=bas*10/100;da=bas*50/100;
	}
	else if(bas>4000 && bas<=8000)
	{
		hra=bas*20/100;da=bas*60/100;
	}
	else if(bas>8000 && bas<=12000)
	{
		hra=bas*25/100;da=bas*70/100;
	}
	else if(bas>12000)
	{
		hra=bas*30/100;da=bas*80/100;
	}
	printf("Gross:%d",bas+hra+da);
	return 0;
}

