// program 13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string.h>
using namespace std;
int expand(char *s1, char *s2)
{
	int i, j = 1; s2[0] = s1[0];
	for (i = 1; i < strlen(s1); i++)
	{
		if (s1[i] == '-')
		{
			if ((s1[i - 1] >= 'a' && s1[i + 1] <= 'z') || (s1[i-1] >= '0' && s1[i+1]<='9'))
			{
				//char c = (char)(s1[i - 1] + 1); cout << "char:" << c << endl;
				for (char c = (char)(s1[i - 1] + 1); c < (char) (s1[i + 1]); c = (char)(c+1))
				{
					s2[j++] = (char)c;
				}
			}
		}
		else
		{
			s2[j++] = s1[i];
		}
	}
	s2[j] = '\0';
	return 0;
}
int main()
{
	char *s1 = (char *)malloc(100 * sizeof(char)); int i;
	cout << "Enter string" << endl;
	scanf("%[^\n]s", s1);
	char *s2 = (char *)malloc(100 * sizeof(char));
	expand(s1, s2);
	cout << "Expanded string:";
	cout << s2 << endl;
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
