// program 15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
char* strcpy1(char* d, char *s)
{
	int i;
	for (i = 0; s[i] != '\0'; i++) d[i] = s[i];
	return d;
}
char* strcat1(char* d, char *s)
{
	int i, j;
	for (i = 0; d[i] != '\0'; i++);
	for (j = 0; s[j] != '\0'; j++)
	{
		d[i++] = s[j];
	}
	d[i] = '\0';
	return d;
}
int strcmp1(char* s1, char* s2)
{
	int i = 0;
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i]) return s1[i] - s2[i];
	}
	return 0;
}
char* strrev1(char* s)
{
	int i = 0, j = 0; char t;
	for (j = 0; s[j] != '\0'; j++);
	j--;
	for (i = 0; i < j; i++, j--)
	{
		t = s[i]; s[i] = s[j]; s[j] = t;
	}
	return s;
}
int main()
{
	char s1[100], s2[100];
	cout << "Enter s1" << endl;
	cin >> s1;
	cout << "Enter s2" << endl;
	cin >> s2;
	cout <<"strcpy:"<< strcpy1(s1, s2) << endl;
	cout << "strrev:" << strrev1(s1) << endl;
	cout << "strcmp:" << strcmp1(s1, s2) << endl;
	cout << "strcat:" << strcat1(s1, s2) << endl;
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
