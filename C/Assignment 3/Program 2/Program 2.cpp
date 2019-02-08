// Program 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<stdio.h>
int main()
{
	int n; scanf_s("%d", &n);
	int *a = (int*)malloc(n * sizeof(int));
	int i, j = 0;
	for (i = 0; i < n; i++) scanf_s("%d", &a[i]);
	int l = 0, r = n - 1, t; i = 0; j = n - 1;
	while (a[i] < 0) i++;
	while (a[j] >= 0) j--;
	l = i; r = n - 1;
	while (l < r)
	{
		if (a[l] >= 0)
		{
			t = a[l]; a[l] = a[r]; a[r] = t;
			r--;
			while (a[r] >= 0) r--;
		}
		l++;
	}
	printf("Array is:\n");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
