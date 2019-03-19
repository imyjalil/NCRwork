#include "pch.h"
#include <iostream>
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<tchar.h>
using namespace std;
int main()
{
	char c1 = 'A';
	CHAR c2 = 'B';
	wchar_t c3 = L'C';
	WCHAR c4 = L'D';
	cout << "displaying characters" << endl;
	cout << c1 << " " << c2 << endl;
	printf("%c %c\n", c3, c4);
	cout << "displaying sizes" << endl;
	cout << sizeof(c1) << " " << sizeof(c2) << " " << sizeof(c3) << " " << sizeof(c4) << endl;
	TCHAR c5 = TEXT('a');
	printf("%c\n", c5);
	cout << sizeof(c5) << endl;
	char arr[] = "abc";
	wchar_t arr1[] = L"def";
	cout << arr << endl;
	printf("%S\n", arr1);
	printf("unicode for arr1: %d\n", IsTextUnicode(arr1, wcslen(arr1) + 1, NULL));
	printf("unicode for arr: %d\n", IsTextUnicode(arr, strlen(arr) + 1, NULL));
	/*****
		Wide character to Multibyte
	*****/
	int return_value = WideCharToMultiByte(CP_UTF8, 0, arr1, -1, NULL, 0, NULL, NULL);
	//int return_value = WideCharToMultiByte(CP_UTF8, 0, arr1, 0, NULL, 0, NULL, NULL);//for error
	if (return_value == 0)
	{
		printf("Error code: %d", GetLastError());
	}
	else
	{
		CHAR *c6;
		c6 = new CHAR[return_value];
		WideCharToMultiByte(CP_UTF8, 0, arr1, -1, c6, return_value, NULL, NULL);
		printf("Wide character to Multibyte: %s\n", c6);
		free(c6);
	}
	/*****
		 Multibyte to Wide character
	*****/
	int return_value2 = MultiByteToWideChar(CP_UTF8, 0, arr, -1, NULL, 0);
	if (return_value2 == 0)
	{
		printf("Error code: %d", GetLastError());
	}
	else
	{
		wchar_t *widechar;
		wchar_t *we;
		widechar = new wchar_t[return_value2];
		MultiByteToWideChar(CP_UTF8, 0, arr, -1, widechar, return_value2);
		printf("Multibyte to Wide character: %S\n", widechar);
		_tprintf(_T("tprintf: %s\n"), widechar);
		printf("length of wide char: %d\n", wcslen(widechar));
		free(widechar);
	}
	return 0;
}