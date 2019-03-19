#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#define EXCEPTION 1
#define MAX_LENGTH 50
using namespace std;

int strlen(char *string1)
{
	int length = 0;
	while (*(string1 + length) != '\0')
	{
		length++;
	}
	return length;
}
void strcpy(char *string2, char *string1)
{
	int i = 0;
	while (*(string1 + i) != '\0')
	{
		*(string2 + i) = *(string1 + i);
		i++;
	}
	*(string2 + i) = '\0';
}
int strcmp(char *string1, char *string2)
{
	int i = 0, j = 0;
	char string1char = *(string1 + i), string2char = *(string2 + j);
	while (string1char == string2char)
	{
		i++;j++;
		if (i >= strlen(string1))
			break;
		if (j >= strlen(string2))
			break;
		string1char = *(string1 + i);
		string2char = *(string2 + j);
	}
	if (string1char > string2char)
	{
		return 1;
	}
	else if (string2char > string1char)
	{
		return -1;
	}
	if (*(string1 + i) == '\0' && *(string2 + j) == '\0')
		return 0;
	else if (*(string1 + i) == '\0')
		return -1;
	else if (*(string2 + j) == '\0')
		return 1;
}
void strcat(char *string1, char *string2)
{
	int length1 = strlen(string1);
	int length2 = strlen(string2);
	if (length1 + length2 > MAX_LENGTH)
	{
		printf("Array index out of bounds\n");
		system("pause");
		exit(1);
	}
	int j = length1;
	for (int i = 0; i < length2; i++, j++)
	{
		*(string1 + j) = *(string2 + i);
	}
	*(string1 + j) = '\0';
}
void strrev(char *string1)
{
	int length = strlen(string1);
	char *string2 = (char *)calloc(length + 1, sizeof(char));
	int i = length - 1;
	for (int j = 0; i >= 0; i--, j++)
	{
		*(string2 + i) = *(string1 + j);
	}
	*(string2 + length) = '\0';
	strcpy(string1, string2);
}

int main()
{
	int length1 = -1, length2 = -1;
	char string1[MAX_LENGTH], string1copy[MAX_LENGTH], string2[MAX_LENGTH], enter[2];
	printf("Enter size of the string : ");
	scanf("%d", &length1);
	if (length1 >= MAX_LENGTH)
	{
		printf("Cannot have length more than %d\n", MAX_LENGTH - 1);
		system("pause");
		exit(1);
	}
	gets_s(enter, 1);
	printf("Enter string1: ");
	try
	{
		gets_s(string1, MAX_LENGTH);
		if (strlen(string1) > length1)
			throw EXCEPTION;
	}
	catch (int exception)
	{
		printf("Array size exception\n");
		system("pause");
		exit(1);
	}
	printf("String entered is %s\n", string1);
	printf("Performing strcpy\n");
	strcpy(string1copy, string1);
	printf("Copy of string1 is %s\n", string1copy);
	printf("Enter size of string2:");
	scanf("%d", &length2);
	if (length2 >= MAX_LENGTH)
	{
		printf("Cannot have length more than %d\n", MAX_LENGTH-1);
		system("pause");
		exit(1);
	}
	gets_s(enter, 1);
	printf("Enter string2:");
	try
	{
		gets_s(string2, MAX_LENGTH);
		if (strlen(string2) > length2)
			throw EXCEPTION;
	}
	catch (int exception)
	{
		printf("Array size exception\n");
		system("pause");
		exit(1);
	}
	printf("String entered is %s\n", string2);
	int str_diff = strcmp(string1, string2);
	printf("strcmp(%s,%s)=%d\n", string1, string2, str_diff);
	int str1len = strlen(string1);
	printf("Length of %s: %d\n", string1, str1len);
	printf("concatenation of string1 and string2:");
	strcat(string1, string2);
	printf(" %s\n", string1);
	printf("reverse of string1:");
	strrev(string1);
	printf(" %s\n", string1);
	system("pause");
	return 0;
}