#include "pch.h"
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n; cout << "Enter no of elements" << endl; cin >> n; int i, j, l = 0, r = n - 1;
	int *a;
	a = (int *)malloc(n * sizeof(int));
	cout << "Enter array elements" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i < n; i++)
	{
		if (a[i] >= 0)
		{
			l = i; i++;
		}
		else break;
	}
	for (i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			r = i; i--;
		}
		else break;
	}
	for (i = l; i < n; i++)
	{
		if (a[i] >= 0)
		{
			for (j = r; j >= 0; j--)
			{
				if (a[j] < 0) break;
			}
			if (a[j] < 0)
			{
				a[i] = a[i] + a[j] - (a[j] = a[i]);
				r--; l++;
			}
			else break;
		}
		else if (a[i] < 0)
		{
			for (j = l; j < n; j++)
			{
				if (a[j] >= 0) break;
			}
			if (a[j] >= 0)
			{
				a[i] = a[i] + a[j] - (a[j] = a[i]);
				r--; l++;
			}
			else break;
		}
	}
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}