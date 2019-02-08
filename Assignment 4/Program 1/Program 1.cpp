// Program 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	float table[2][3] = { {1.1,1.2,1.3},{2.1,2.2,2.3} };
	cout << table << endl;//a---
	cout << table + 1 << endl;//b--
	cout << *(table + 1) << endl;//c
	cout << (*(table + 1) + 1) << endl;//d
	cout << (*(table)+1) << endl;//e
	cout << *(*(table + 1) + 1) << endl;//f
	cout << *(*(table)+1) << endl;
	cout << *(*(table + 1)) << endl;
	cout << *(*(table)+1) + 1 << endl;
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
