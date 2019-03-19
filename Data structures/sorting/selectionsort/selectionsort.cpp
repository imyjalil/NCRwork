#include "pch.h"
#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
	int t = *a; *a = *b; *b = t;
}
void selectionsort(int a[], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		int ind=-1,ma = 9999;
		for (j = i; j < n; j++)
		{
			if (a[j] < ma)
			{
				ma = a[j]; ind = j;
			}
		}
		swap(&a[i], &a[ind]);
	}
}
int main()
{
	int n; cout << "Enter no. of elements" << endl; cin >> n; cout << "Enter elements" << endl; int *a = new int[n];
	int i, j;
	for (i = 0; i < n; i++) cin >> a[i];
	selectionsort(a, n);
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}