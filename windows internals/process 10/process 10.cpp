#include "pch.h"
#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
int _tmain(int argc, TCHAR *argv[])
{
	LPCWSTR file = L"abc.txt";
	HANDLE filehandle;
	SECURITY_ATTRIBUTES secattr;
	secattr.bInheritHandle = TRUE;
	secattr.lpSecurityDescriptor = NULL;
	secattr.nLength = sizeof(secattr);
	filehandle = CreateFileW(
		file, 
		GENERIC_READ, 
		0,     
		&secattr,   
		OPEN_EXISTING, 
		FILE_ATTRIBUTE_NORMAL,
		NULL   
	);
	if (INVALID_HANDLE_VALUE == filehandle)
	{
		_tprintf(_T(" file not created\n"));
		exit(0);
	}
	else
	{
		_tprintf(_T("file created\n"));
	}
	printf("Creating child process\n");
	STARTUPINFO  startinfo;
	PROCESS_INFORMATION procinfo;
	ZeroMemory(&startinfo, sizeof(startinfo));
	ZeroMemory(&procinfo, sizeof(procinfo));
	startinfo.cb = sizeof(startinfo);
	BOOL proc;
	proc = CreateProcess(NULL, 
		argv[1], 
		NULL, 
		NULL, 
		TRUE, 
		NORMAL_PRIORITY_CLASS, 
		NULL, 
		NULL, 
		&startinfo, 
		&procinfo
	);
	if (proc == 0)
	{
		printf("process not created:%d\n", GetLastError());
		return 0;
	}
	printf("process created\n");
	getchar();
	system("pause");
	return 0;
}