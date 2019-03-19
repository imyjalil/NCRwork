#include "pch.h"
#include <iostream>
#include<string.h>
using namespace std;
bool checkalpha(char a, char b)//true if letter a is less than or equal to b
{
	if ((a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z') || (a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z'))
	{
		if(a<=b) return true;
		return false;
	}	
	return false;
}
bool checkdigit(char a, char b)//true if digit a is less than or equal to b
{
	if (a >= '0' && a <= '9' && b >= '0' && b <= '9')
	{
		if (a <= b) return true;
		return false;
	}
	return false;
}
char* expand(char *string1, char *string2)
{
	string2 = (char *)malloc((strlen(string1) +1)* sizeof(char));
	int i, j = 1; string2[0] = string1[0];
	for (i = 1; i < strlen(string1) - 1; i++)
	{
		if (string1[i] == '-')
		{
			if ((checkalpha(string1[i - 1], string1[i + 1])) || (checkdigit(string1[i - 1], string1[i + 1])))
			{
				if (string1[i - 1] == string1[i + 1])//a-a -> a
				{
					i++;
				}
				else//a-c -> abc
				{
					//reallocate memory according to the number of characters to be accomodated
					string2 = (char *)realloc(string2, (strlen(string2) + 1 + (string1[i+1]-string1[i-1]-1)) * sizeof(char));
					for (char c = (char)(string1[i - 1] + 1); c < (char)(string1[i + 1]); c = (char)(c + 1))
					{
						string2[j++] = (char)c;
					}
				}
			}
			else
			{
				string2[j++] = string1[i];
			}
		}
		else
		{
			string2[j++] = string1[i];
		}
	}
	string2[j++] = string1[i++];
	string2[j] = '\0';
	return string2;
}
int main()
{
	char *string1 = (char *)malloc(100 * sizeof(char));
	cout << "Enter string" << endl;
	scanf("%[^\n]s", string1);
	char *string2 = NULL;
	string2 = expand(string1, string2);
	cout << "Expanded string:";
	cout << string2 << endl;
	free(string1); free(string2);
}