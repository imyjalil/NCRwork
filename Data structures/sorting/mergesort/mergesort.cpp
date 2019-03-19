#include "pch.h"
#include<iostream>
#include<stdlib.h>
using namespace std;
void merge(int arr[], int low, int mid, int high)
{
	int i = low, j = mid + 1, k = 0;
	int *arr1 = (int *)malloc((high - low + 1) * sizeof(int));
	while (i <= mid && j <= high)
	{
		if (arr[i] < arr[j]) arr1[k++] = arr[i++];
		else arr1[k++] = arr[j++];
	}
	while (i <= mid) arr1[k++] = arr[i++];
	while (j <= high) arr1[k++] = arr[j++];
	for (i = low, j = 0; i <= high; i++, j++) arr[i] = arr1[j];
	free(arr1);
}
void mergesort(int arr[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		mergesort(arr, low, mid);
		mergesort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}
int main()
{
	int n = -1, i, low, high;
	cout << "Enter no. of elements " << endl;
	cin >> n; int *arr = new int[n];
	for (i = 0; i < n; i++)
	{
		cout << "Enter element " << i + 1 << endl;
		cin >> arr[i];
	}
	mergesort(arr, 0, n-1);
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	free(arr);
	return 0;
}