#include<stdio.h>
int main()
{
	int n;scanf("%d",&n);
	int sum=0;int num=n;
	while(num>0)
	{
		sum=sum+(num%10);num/=10;
	}
	printf("%d",sum);
	return 0;
}

