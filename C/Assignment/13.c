/*
invert b bits from position p
*/
#include<stdio.h>
#include<math.h>
int invertponwards(int n,int p,int b)
{
	int num=n,nu=floor(log(n)/log(2));
	int j,i=0,bin[1+nu];
	while(num>0)
	{
		bin[i++]=num%2;num/=2;
	}
	printf("Binary representation before altering:");
	for(j=0;j<i;j++) printf("%d",bin[j]);printf("\n");
	for(j=p;j<p+b;j++) bin[j]=(bin[j]+1)%2;
	printf("Binary representation before altering:");
	for(j=0;j<i;j++) printf("%d",bin[j]);printf("\n");
	num=0;
	for(j=0;j<i;j++)
	{
		num=num+(bin[j]*pow(2,i-j-1));
	}
	return num;
}
int main()
{
	int n,p,b;scanf("%d%d%d",&n,&p,&b);
	int num=invertponwards(n,p,b);
	printf("Num: %d",num);
	return 0;
}

