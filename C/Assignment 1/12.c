/*
5428
8*1000+542=8542
*/
#include<stdio.h>
#include<math.h>
int len(int num)
{
	return 1+floor(log(num)/log(10));
}
int rotate_right(int n,int b)
{
	int l=len(n);
	while(b>0)
	{
		int num=n%10;n/=10;
		num=num*pow(10,l-1);
		n=num+n;
		b--;
	}
	return n;
}
int main()
{
	int n,b;scanf("%d%d",&n,&b);
	int num=rotate_right(n,b);
	printf("%d",num);
	return 0;
}

