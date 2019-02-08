// program 12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int deletes2(char *s1, char *s2)
{
	int i, j = 0, k, cnt = 0, val = strlen(s1);
	for (i = 0; i < val - cnt; i++)
	{
		//cout << "i=" << i << endl;
		for (k = 0; k < strlen(s2); k++)
		{
			//cout<<s1[i]<<" "<<s2[k]<<endl;
			//cout <<"i= " << i << "k=" << k << endl;
			if (s1[i] == s2[k])
			{
				//cout<<s1[i]<<" "<<s2[k]<<endl;
				//cout << "k=" << k << endl;
				for (j = i + 1; j < val - cnt; j++)
				{
					s1[j - 1] = s1[j];
				}
				s1[j - 1] = '\0';
				cnt++; i--;
				break;
			}
		}
	}
	return 0;
}
int main()
{
	cout << "Enter string1" << endl;
	char *s1 = (char *)malloc(100 * sizeof(char));
	scanf("%[^\n]s", s1);
	cout << "Enter string2" << endl;
	char *s2 = (char *)malloc(100 * sizeof(char));
	scanf(" %[^\n]s", s2);
	//cout << "s1: " << s1 << endl;
	//cout << "s2: " << s2 << endl;
	deletes2(s1, s2);
	cout << s1 << endl;
	return 0;
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
