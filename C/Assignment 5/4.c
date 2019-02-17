#include<stdio.h>
int main()
{
	unsigned int number = 1;
	char *ch = (char *)&number;
	if (*ch)
	{
		printf("Little Endian");
	}
	else
	{
		printf("Big Endian");
	}
	return 0;
}
