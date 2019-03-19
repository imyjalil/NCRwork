#include "pch.h"
#include <iostream>
#include<Windows.h>
#include<tchar.h>
using namespace std;
DWORD WINAPI thread_func(LPVOID lparam)
{
	cout << "In thread" << endl;
	return 0;
}
int _tmain(int argc, TCHAR* argv[])
{
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
		HIGH_PRIORITY_CLASS,
		NULL,
		NULL,
		&startinfo,
		&procinfo
	);
	if (proc == 0)
	{
		cout << " couldn't create process, error code: " << GetLastError() << endl;
		return 0;
	}
	BOOL ret = SetPriorityClass(procinfo.hProcess, BELOW_NORMAL_PRIORITY_CLASS);
	if (ret == 0)
	{
		cout << "Couldn't change priority, error code: " << GetLastError() << endl;
		return 0;
	}
	else
	{
		cout << "Process priority changed to below normal" << endl;
	}
	DWORD threadid;
	HANDLE threadhandle = CreateThread(
		NULL,
		0,
		thread_func,
		NULL,
		0,
		&threadid
	);
	if (threadhandle == NULL)
	{
		cout << "Couldn't create thread, error code: " << GetLastError() << endl;
	}
	WaitForSingleObject(threadhandle, INFINITE);
	BOOL retthread = SetThreadPriority(threadhandle, THREAD_PRIORITY_LOWEST);
	if (retthread == 0)
	{
		cout << "Couldn't change thread priority, error code: " << GetLastError() << endl;
		return 0;
	}
	else
	{
		cout << "Thread priority changed to lowest" << endl;
	}
	CloseHandle(procinfo.hProcess);
	CloseHandle(procinfo.hThread);
	system("pause");

}