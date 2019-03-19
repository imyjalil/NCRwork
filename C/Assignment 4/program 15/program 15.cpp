#include "pch.h"
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
char* strcpy1(char* dest, char *source)
{
	int i;
	for (i = 0; source[i] != '\0'; i++) *(dest + i) = *(source + i);
	*(dest + i) = '\0';
	return dest;
}
char* strcat1(char* dest, char *source)
{
	int i, j;
	for (i = 0; dest[i] != '\0'; i++);
	for (j = 0; source[j] != '\0'; j++)
	{
		*(dest + i++) = *(source + j);
	}
	*(dest + i) = '\0';
	return dest;
}
int strcmp1(char* s1, char* s2)
{
	int i = 0;
	int minlen = 0;
	if (strlen(s1) < strlen(s2)) minlen = strlen(s1);
	else minlen = strlen(s2);
	for (i = 0; i < minlen; i++)
	{
		if (*(s1 + i) != *(s2 + i))
		{
			if (*(s1 + i) < *(s2 + i))
			{
				return -1;
			}
			return 1;
		}
	}
	if (strlen(s1) > strlen(s2)) return 1;
	else if (strlen(s1) < strlen(s2)) return -1;
	return 0;
}
char* strrev1(char* string1)
{
	int i = 0, j = 0; char t;
	for (j = 0; string1[j] != '\0'; j++);
	j--;
	for (i = 0; i < j; i++, j--)
	{
		t = *(string1 + i); *(string1 + i) = *(string1 + j); *(string1 + j) = t;
	}
	return string1;
}
int strlen1(char *s)
{
	int i = 0, length = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		length++;
	}
	return length;
}
int main()
{
	cout << "Enter length of string 1" << endl; int string1len; cin >> string1len;
	char *string1 = (char*)calloc(string1len + 1, sizeof(char)); char pre[2];
	gets_s(pre,2);
	cout << "Enter string1" << endl;
	fgets(string1, string1len + 1, stdin);
	cout << "Enter length of string 2" << endl; int string2len; cin >> string2len;
	char *string2 = (char*)calloc(string2len + 1, sizeof(char));
	gets_s(pre, 2);
	cout << "Enter s2" << endl;
	fgets(string2, string2len + 1, stdin);
	cout << "string1=" << string1 << endl;
	cout << "string2=" << string2 << endl;
	string1 = (char *)realloc(string1, strlen(string2) + 1);
	strcpy1(string1, string2);
	cout <<"strcpy:"<< string1 << endl;
	cout << "string1=" << string1 << endl;
	cout << "string2=" << string2 << endl;
	string1 = strrev1(string1);
	cout << "strrev:" << string1 << endl;
	cout << "string1=" << string1 << endl;
	cout << "string2=" << string2 << endl;
	cout << "strcmp:" << strcmp1(string1, string2) << endl;
	cout << "string1=" << string1 << endl;
	cout << "string2=" << string2 << endl;
	string1 = (char *)realloc(string1, strlen1(string1) + strlen1(string2) + 1);
	cout << "strcat:" << strcat1(string1, string2) << endl;
	cout << "string1=" << string1 << endl;
	cout << "string2=" << string2 << endl;
	free(string2);
	cout << "exit" << endl;
	return 0;
}