// Program 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<stdio.h>
int main()
{
	long int n, f = 1;
	int i;
	printf("enter n\n");
	scanf_s("%ld", &n);
	for (i = 1; i <= n; i++)
		f = f * i;
	printf("Factorial = %ld", f);
	return 0;
}