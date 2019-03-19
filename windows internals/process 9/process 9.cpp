#include "pch.h"
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include<iostream>
using namespace std;
int _tmain(int argc, TCHAR *argv[])
{
	STARTUPINFO startinfo;
	PROCESS_INFORMATION processinfo;

	ZeroMemory(&startinfo, sizeof(startinfo));
	startinfo.cb = sizeof(startinfo);
	ZeroMemory(&processinfo, sizeof(processinfo));

	if (argc != 2)
	{
		printf("Usage: %s [cmdline]\n", argv[0]);
		system("pause");
		return 0;
	}


	BOOL process = CreateProcess(NULL,
		argv[1],
		NULL,
		NULL,
		TRUE,
		0,
		NULL,
		NULL,
		&startinfo,
		&processinfo);

	if (!process)
	{
		printf("CreateProcess failed (%d).\n", GetLastError());

		return 0;
	}

	DWORD currprocId = GetCurrentProcessId();
	cout << " Current process ID: " << currprocId << endl;
	DWORD threadID = GetCurrentThreadId();
	cout << " Current thread ID: " << threadID << endl;
	DWORD procId = GetProcessId(processinfo.hProcess);
	cout << "Process ID:" << procId << endl;
	DWORD procIdOfThread = GetProcessIdOfThread(processinfo.hThread);
	wcout << "Process ID of Thread:" << procIdOfThread << endl;
	WaitForSingleObject(processinfo.hProcess, INFINITE);

	system("pause");

	return 0;
}