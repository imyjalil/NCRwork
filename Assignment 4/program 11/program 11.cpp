// program 11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"// program 11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main()
{
	cout << "Enter string" << endl;
	char *s; s = (char *)malloc(100 * sizeof(char));
	scanf("%[^\n]s", s);
	cout << "Enter delimiter" << endl; char c; cin >> c; int i, j, val, cnt = 0;
	char **res;
	for (i = 0; i < strlen(s); i++)
		if (s[i] == '-')
			cnt++;
	//cout <<"cnt="<< cnt << endl;
	res = (char **)malloc((cnt + 1) * sizeof(char *)); int k;
	j = 0;
	for (i = 0; i < cnt; i++)
	{
		val = j;
		while (s[j] != c) j++;
		//cout << "j=" << j << " val=" << val << endl;
		res[i] = (char *)malloc((j - val + 1) * sizeof(char));
		for (k = 0; k < j - val; k++)
		{
			res[i][k] = s[k + val];
		}
		res[i][k] = '\0';
		j++;
	}
	res[i] = (char *)malloc((j - val + 1) * sizeof(char));
	for (k = 0; k < strlen(s) - j; k++) res[i][k] = s[k + j];
	res[i][k] = '\0';
	for (i = 0; i <= cnt; i++)
	{
		printf("%s\n", res[i]);
	}
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
