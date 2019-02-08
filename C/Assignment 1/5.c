#include<stdio.h>
int ispal(int n)
{
	int k=n,num=0;
	while(k>0)
	{
		num=num*10+k%10;k/=10;
	}
	return num==n;
}
int main()
{
	int n;scanf("%d",&n);
	puts(ispal(n)?"Palindrome":"Not Palindrome");
	return 0;
}
