// program 10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string.h>
using namespace std;
int del(char *s, char c)
{
	int i, j = 0, cnt = 0, val=strlen(s);
	for (i = 0; i < val - cnt; i++)
	{
		if (s[i] == c)
		{
			for (j = i + 1; j < val - cnt; j++)
			{
				s[j-1] = s[j];
			}
			s[j-1] = '\0';
			cnt++;
		}
	}
	return 0;
}
int main()
{
	char *s, c;
	cout << "Enter string" << endl;
	s = (char *)malloc(100 * sizeof(char));
	scanf("%[^\n]s", s);
	cout << "Enter character" << endl; cin >> c;
	del(s, c);
	cout << "string is" << endl;
	printf("%s", s);
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
