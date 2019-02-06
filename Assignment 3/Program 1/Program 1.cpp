// Program 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int i, j, n, sreq; cout << "Enter no of elements" << endl; cin >> n;
	int *a;
	a = (int *)malloc(n * sizeof(int));
	cout << "Enter array elements" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "Enter sum req:" << endl;
	cin >> sreq;
	for (i = 0; i < n; i++)
	{
		if (sreq == a[i])
		{
			cout << "Sum found at " << i << endl; return 0;
		}
	}
	int s = 0;
	for (i = 0; i < n; i++)
	{
		s = 0;
		for (j = i; j < n; j++)
		{
			if (s >= sreq) break;
			s += a[j];
		}
		if (s == sreq )
		{
			cout << "sum found between " << i << " and " << j - 1 << endl; break;
		}
	}
	if (i == n)
	{
		cout << "No subarray found" << endl;
	}
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
