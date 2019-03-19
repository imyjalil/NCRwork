#include "pch.h"
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<tchar.h>
#define MAX_SIZE 100
using namespace std;
int main()
{
	LPCWSTR fileloc = L"file.txt";
	HANDLE hFile = CreateFile(
		fileloc,//filename
		GENERIC_READ,//access mode
		0,//share
		NULL,//security
		OPEN_EXISTING,//creation disposition
		FILE_ATTRIBUTE_NORMAL,//flag
		NULL//htemplate
		);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		printf("Unable to open file.... error code: %d\n", GetLastError());
		return 0;
	}
	CHAR buf[MAX_SIZE];
	DWORD numbytesread;
	BOOL bread;
	while (1)
	{
		ZeroMemory(buf, MAX_SIZE);
		bread = ReadFile(
			hFile,
			buf,
			MAX_SIZE-1,
			&numbytesread,
			NULL
		);
		if (bread == FALSE)
		{
			printf("Error in reading, error code: %d\n", GetLastError());
			return 0;
		}
		if (numbytesread < MAX_SIZE - 1)
		{
			printf("%s", buf);
			break;
		}
		printf("%s", buf);
	}
	CloseHandle(hFile);
	return 0;
	
}