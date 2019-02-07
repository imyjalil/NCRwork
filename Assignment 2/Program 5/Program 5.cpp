// Program 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<stdio.h>
int main()
{
	int n, r, s = 0;
	printf("Enter n\n");
	scanf_s("%d", &n);
	while (n > 0)
	{
		r = n % 10;
		s = s * 10 + r;
		n = n / 10;
	}
	printf("Reverse:%d", s);
	return 0;
}