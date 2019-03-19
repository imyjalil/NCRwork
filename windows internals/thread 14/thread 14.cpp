#include "pch.h"
#include <iostream>
#include<Windows.h>
using namespace std;
DWORD exitcode;
DWORD WINAPI thread_func(LPVOID param)
{
	printf("In secondary thread\n");
	printf("Exiting secondary thread\n");
	ExitThread(exitcode);
}
int main()
{
	DWORD threadid;
    HANDLE threadhandle = CreateThread(
		NULL,
		0,
		thread_func,
		NULL,
		0,
		&threadid);
	BOOL exitval = GetExitCodeThread(threadhandle, &exitcode);
	
	WaitForSingleObject(threadhandle, INFINITE);
	if (exitval != 0)
	{
		cout << "Thread exited succesfully" << endl;
		cout << "exit code:" << exitcode << endl;
	}
	else
	{
		cout << "Thread exit failed" << endl;
	}
	system("pause");
}