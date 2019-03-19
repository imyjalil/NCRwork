#include "pch.h"
#include <iostream>
using namespace std;
void insertionsort(int a[], int n)
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		j = i - 1; int t = a[i];
		//cout << "i=" << i << endl;
		while (j >= 0 && a[j] > t)
		{
			//cout << "i=" << i << " j=" << j << endl;
			//cout << a[j + 1] << " = " << a[j] << endl;
			a[j + 1] = a[j];
			 j--;

		}
		//cout << "t, a[" << j + 1 << "] = a[" << j <<"]"<< endl;
		a[j+1] = t;
		//for (j = 0; j < n; j++) cout << a[j] << " "; cout << endl;
	}
}
int main()
{
	int n; cout << "Enter no. of elements" << endl; cin >> n; cout << "Enter elements" << endl; int *a = new int[n];
	int i, j;
	for (i = 0; i < n; i++) cin >> a[i];
	insertionsort(a, n);
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}