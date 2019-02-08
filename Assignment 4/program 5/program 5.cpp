// program 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
using namespace std;
int main()
{
	char *cat;
	cat = (char *)malloc(100 * sizeof(char));
	cin >> cat;
	printf("lower to upper\n");
	//cin >> cat;
	int i;
	for(i=0;cat[i]!='\0';i++)
		if(islower(cat[i]))
			cat[i]=toupper(cat[i]);
	cout<<cat<<endl;
	printf("upper to lower\n");
	cin >> cat;
	for (i = 0; cat[i] != '\0'; i++)
		if (isupper(cat[i]))
			cat[i] = tolower(cat[i]);
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
