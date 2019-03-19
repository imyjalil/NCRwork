#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define MAX 100
using namespace std;

int strlen1(char *s)
{
	int i = 0, len = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		len++;
	}
	return len;
}
int strcmp(char *string1, char *string2)
{
	int i = 0, minlen = 0;
	if (strlen1(string1) < strlen(string2))
	{
		minlen = strlen1(string1);
	}
	else minlen = strlen1(string2);
	for (i = 0; i < minlen; i++)
	{
		if (*(string1 + i) < *(string2 + i))
		{
			return -1;
		}
		else if (*(string1 + i) > *(string2 + i))
		{
			return 1;
		}
	}
	if (strlen1(string1) == strlen1(string2))
	{
		return 0;
	}
	if (strlen1(string1) > strlen(string2))
	{
		return 1;
	}
	return -1;
}
char* strrev1(char *s)
{
	int i = 0, j = 0; char t;
	for (i = 0; s[i] != '\0'; i++);
	i--;
	for (; j < i; j++, i--)
	{
		t = *(s + i); *(s + i) = *(s + j); *(s + j) = t;
	}
	return s;
}
char* strcat1(char *s1, char *s2)
{
	int i = 0, j = 0;
	for (i = 0; s1[i] != '\0'; i++);
	for (; s2[j] != '\0'; j++, i++)
	{
		s1[i] = s2[j];
	}
	s1[i] = '\0';
	return s1;
}
char * strcpy1(char* s1, char* s2)
{
	int i = 0;
	for (i = 0; s2[i] != '\0'; i++)
	{
		s1[i] = s2[i];
	}
	s1[i] = '\0';
	return s1;
}
int main()
{
	int len1 = 0, len2 = 0;
	char *string1 = (char *)malloc(MAX * sizeof(char));
	char *string2 = (char *)malloc(MAX * sizeof(char));
	char dup[2];
	cout << "Enter length of string 1" << endl;
	cin >> len1;
	if (len1 > MAX)
	{
		cout << "Entered invalid length" << endl;
		return 0;
	}
	gets_s(dup, 2);
	cout << "Enter string 1" << endl;
	fgets(string1, len1+1, stdin);
	cout << "Enter length of string 2" << endl;
	cin >> len2;
	if (len2 > MAX)
	{
		cout << "Entered invalid length" << endl;
		return 0;
	}
	gets_s(dup, 2);
	cout << "Enter string 2" << endl;
	fgets(string2, len2+1, stdin);
	cout << "Length of string 1: " << strlen1(string1) << endl;
	cout << "Length of string 2: " << strlen1(string2) << endl;
	cout << "string1: " << string1 << endl;
	cout << "string2: " << string2 << endl;
	cout << "strcmp: " << strcmp(string1, string2) << endl;
	cout << "Reversing string1" << endl;
	strrev1(string1);
	cout << "string1: " << string1 << endl;
	cout << "concatenating string1 with string2" << endl;
	strcat1(string1, string2);
	cout << "string1: " << string1 << endl;
	cout << "copying string2 to string1" << endl;
	strcpy1(string1, string2);
	cout << "string1: " << string1 << endl;
	free(string1); free(string2);
}