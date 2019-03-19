#include "pch.h"
#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
	int t = *a; *a = *b; *b = t;
	//*a = *a + *b - (*b = *a);
}
int main()
{
	cout << "Enter no. of elements" << endl; int i, j, n, flag=0; cin >> n;
	int *a = new int[n];
	cout << "enter elements" << endl;
	for (i = 0; i < n; i++) cin >> a[i];
	for (i = 0; i < n-1; i++)
	{
		flag = 0;
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				flag = 1;
				swap(&a[j], &a[j+1]);
			}
		}
		if (flag == 0) break;
	}
	cout << "Array after sorting is" << endl;
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}