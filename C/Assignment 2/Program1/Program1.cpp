// Program1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	int a; cin >> a;
	int bin[10000];
	int j, i=0, n = a;
	while (n > 0)
	{
		bin[i++] = n % 2;
		n /= 2;
	}
	for (j = i-1; j >= 0; j--) cout << bin[j];
	cout << endl; int b, num;
	cin >> b;
	i = 0; n = b, num=0;
	while (n > 0)
	{
		num = num +(( n % 10) * pow(2, i++));
		n /= 10;
	}
	cout << num << endl;
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
