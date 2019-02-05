#include<stdio.h>
#include<math.h>
int main()
{
	int n,k=3;scanf("%d",&n);
	int s=0,num=n;
	while(num>0)
	{
		s=s+pow(num%10,k);num/=10;
	}
	if(s==n) printf("Armstrong");
	else printf("Not Armstrong");
	return 0;
}

