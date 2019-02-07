// Program 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
int isprime(int n)
{
	for (int i = 2; i*i <= n; i++)
	{
		if (n%i == 0) return 0;
	}
	return 1;
}
int main()
{
	int s, e;
	printf("Enter start and end\n");
	scanf_s("%d%d", &s, &e);
	for (int i = s; i <= e; i++)
		if (isprime(i))
			printf("%d ", i);
}