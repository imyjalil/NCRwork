#include<stdio.h>
#include<conio.h>
int main()
{
	int n = -1;char b[5];
	printf("Enter number between 0 and 32:");
	scanf("%d",&n);
	if (n >= 0 && n < 32)
	{
		int k = n, r = -1, i = 3, it;
		while(k)
		{
			r = k % 2;
			b[i] = r+48;
			k /= 2;
			i--;
		}
		b[4] = '\0';
		for (it = i+1; it <= 3; it++)
		{
			printf("%c",b[it]);
		}
		printf("\n");
	}
	return 0;
}
