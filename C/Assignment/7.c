#include<stdio.h>
int min(int a,int b)
{
	return a<b?a:b;
}
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int n,mi=100000,ma=0,poscount=0,sum=0;
	while(1)
	{
		scanf("%d",&n);
		if(n<=0) break;
		poscount++;
		sum+=n;
		mi=min(mi,n);
		ma=max(ma,n);
	}
	printf("No. of positives:%d\nMinimum:%d\nMaximum:%d\nAverage:%d\n",poscount,mi,ma,sum/poscount);
	return 0;
}
