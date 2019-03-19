#include "pch.h"
#include <windows.h>
#include <stdio.h>
#include <tchar.h>

int _tmain(int argc, TCHAR *argv[])
{
	STARTUPINFO startinfo1, startinfo2;
	PROCESS_INFORMATION processinfo1, processinfo2;

	ZeroMemory(&startinfo1, sizeof(startinfo1));
	startinfo1.cb = sizeof(startinfo1);
	ZeroMemory(&processinfo1, sizeof(processinfo1));

	ZeroMemory(&startinfo2, sizeof(startinfo2));
	startinfo2.cb = sizeof(startinfo2);
	ZeroMemory(&processinfo2, sizeof(processinfo2));

	if (argc < 3 || argc > 3)
	{
		printf("Incorrect usage. Usage: %s [cmdline] [cmdline]\n", argv[0]);
		return 0;
	}


	BOOL process1 = CreateProcess(NULL,
		argv[1],
		NULL,
		NULL,
		TRUE,
		0,
		NULL,
		NULL,
		&startinfo1,
		&processinfo1);

	if (!process1)
	{
		printf("CreateProcess failed (%d).\n", GetLastError());

		return 0;
	}

	BOOL process2 = CreateProcess(NULL,
		argv[2],
		NULL,
		NULL,
		TRUE,
		0,
		NULL,
		NULL,
		&startinfo2,
		&processinfo2);

	if (!process2)
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
		return 0;
	}

	HANDLE prochandle[2];
	prochandle[0] = processinfo1.hProcess;
	prochandle[1] = processinfo2.hProcess;
	// Wait until child process exits.
	//WaitForSingleObject(processinfo1.hProcess, INFINITE);
	WaitForMultipleObjects(2, prochandle, TRUE, INFINITE);

	// Close process and thread handles. 
	CloseHandle(processinfo1.hProcess);
	CloseHandle(processinfo2.hProcess);
}