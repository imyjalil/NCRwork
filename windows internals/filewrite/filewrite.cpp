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
	LPCWSTR fileloc = L"filenew.txt";
	HANDLE hFile = CreateFile(
		fileloc,//filename
		GENERIC_WRITE,//access mode
		0,//share
		NULL,//security
		CREATE_ALWAYS,//creation disposition
		FILE_ATTRIBUTE_NORMAL,//flag
		NULL//htemplate
	);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		cout << "Function failed, error code: " << GetLastError() << endl;
		return 0;
	}
	char buf[] = "hello hey there";
	DWORD numbyteswritten;
	BOOL bwrite = WriteFile(
		hFile,
		buf,
		strlen(buf),
		&numbyteswritten,
		NULL
	);
	if (bwrite == FALSE)
	{
		cout << "Couldn't write, error code: " << GetLastError() << endl; return 0;
	}
	cout << "Writing complete, written " << numbyteswritten << " bytes" << endl;
	CloseHandle(hFile);
}