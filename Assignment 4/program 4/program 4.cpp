// program 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
using namespace std;
int replace(char *cat)
{
	int i,cnt =0;
	for (i = 0; i < strlen(cat); i++)
	{
		if (cat[i] == ' ') {
			cat[i] = '-'; cnt++;
		}
	}
	cout << "cnt=" << cnt << endl;
	return 0;
}
int main()
{
	char *cat;
	cat = (char *)malloc(sizeof(100 * sizeof(char)));
	cout << "Enter string" << endl;
	scanf_s("%[^\n]s", cat[100]);
	replace(cat);
	cout << cat << endl;
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
