#include <iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

template <class T>
int lsearch(T *arr,int n, T x)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
			return i;
	}
	return -1;
}

template<>
int lsearch(char **arr, int n,char *x)
{
	for (int i = 0; i < n; i++)
	{

		if (strcmp(arr[i], x) == 0)
			return i;
	}
	return -1;
}
int main()
{
	cout << "1-Int  2-Double  3-String: ";
	int ch, ind=0, ind1=0, ind2=0;
	cin >> ch;
	switch (ch)
	{
	case 1:
		int arrInt[10], n;
		cout << "Enter Size of IntArray: ";
		cin >> n;
		cout << "Enter Int Array Elements\n";
		for (int i = 0; i < n; i++)
		{
			cin >> arrInt[i];
		}
		cout << "Enter Element to Search: ";
		int x;
		cin >> x;
		ind = lsearch(arrInt, n, x);
		if (ind == -1)
			cout << "Element Not Found\n";
		else
			cout << "Element Found at Index: " <<ind <<"\n";

	case 2:
		double arrDouble[10], x1;
		int n1;
		cout << "Enter Size of DoubleArray: ";
		cin >> n1;
		cout << "Enter Double Array Elements\n";
		for (int i = 0; i < n1; i++)
		{
			cin >> arrDouble[i];
		}
		cout << "Enter Element to Search: ";
		cin >> x1;
		ind1 = lsearch(arrDouble, n1, x1);
		if (ind1 == -1)
			cout << "Element Not Found\n";
		else
			cout << "Element Found at Index: " << ind1 << "\n";

	case 3:
		
		char *str[5];
		cout << "Enter Num of Strings: ";
		int n2;
		cin >> n2;
		for (int i = 0; i < n2; i++)
		{
			str[i] = (char * )malloc(n2*sizeof(char *));
		}
		for (int i = 0; i < n2; i++)
		{
			cout << "Enter String " << i + 1 <<endl;
			char temp[10];
			cin >> temp;
			strcpy(str[i], temp);
		}

		char x2[10];
		cout << "Enter String to search"<<endl;
		cin >> x2;
		ind2 = lsearch(str, 3, x2);
		if (ind2 == -1)
			cout << " Not Found"<<endl;
		else
			cout << " Found at " << ind2 <<endl;
	}
}
