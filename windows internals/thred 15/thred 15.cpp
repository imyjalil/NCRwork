#include "pch.h"
#include <iostream>
#include<Windows.h>
using namespace std;
DWORD exitcode, exitval;
HANDLE threadhandle;
DWORD WINAPI thread_func(LPVOID param)
{
	printf("In secondary thread\n");
	printf("Exiting secondary thread\n");
	return 0;
}
int main()
{
	DWORD threadid;
	threadhandle = CreateThread(
		NULL,
		0,
		thread_func,
		NULL,
		0,
		&threadid);
	exitval = GetExitCodeThread(threadhandle, &exitcode);

	WaitForSingleObject(threadhandle, INFINITE);
	BOOL terminateval = TerminateThread(threadhandle, exitcode);
	if (terminateval != 0)
	{
		cout << "Thread exited succesfully" << endl;
		cout << "exit code: " << exitcode << endl;
	}
	else
	{
		cout << "Thread exit failed" << endl;
	}
	system("pause");
}