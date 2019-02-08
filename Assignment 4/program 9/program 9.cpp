// program 9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string.h>
using namespace std;
int any(char *s1,char *s2)
{
	int i, j, k;
	if (strlen(s1) < strlen(s2)) return -1;
	int fin = strlen(s1) - strlen(s2) + 1;
	for (i = 0; i < fin; i++)
	{
		if (s1[i] == s2[0])
		{
			for (j = 0, k = i; j < strlen(s2); j++,k++)
			{
				if (s2[j] != s1[k]) break;
			}
			if (j == strlen(s2)) return i;
		}
	}
	return -1;
}
int main()
{
	char *s1, *s2;
	cout << "Enter s1" << endl;
	s1 = (char *)malloc(100 * sizeof(char));
	scanf("%[^\n]s", s2);
	//cin >> s1;
	s2 = (char *)malloc(100 * sizeof(char));
	cout << "Enter s2" << endl;
	scanf("%[^\n]s", s2);
	//cin >> s2;
	int loc = any(s1, s2);
	if (loc == -1)
		cout << "Not found" << endl;
	else
		cout << "String found at " << loc << endl;
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
