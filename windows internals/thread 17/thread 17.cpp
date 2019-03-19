#include "pch.h"
#include <iostream>
#include<Windows.h>
#include<tchar.h>
using namespace std;
int sharedvar = 0;
DWORD WINAPI thread_func(LPVOID lparam)
{
	sharedvar++;
	cout << "In Thread 1, sharedvar: " << sharedvar << endl;
	return 0;
}
DWORD WINAPI thread_func1(LPVOID lparam)
{
	sharedvar++;
	cout << "In Thread 2, sharedvar: " << sharedvar << endl;
	return 0;
}
int main()
{
	DWORD threadid1, threadid2;
	while (1)
	{
		sharedvar = 0;
		HANDLE threadhandle1 = CreateThread(
			NULL,
			0,
			thread_func,
			NULL,
			0,
			&threadid1);
		if (threadhandle1 == NULL)
		{
			cout << "cannot create thread 1, error code: " << GetLastError() << endl; return 0;
		}
		HANDLE threadhandle2 = CreateThread(
			NULL,
			0,
			thread_func1,
			NULL,
			0,
			&threadid2);
		if (threadhandle2 == NULL)
		{
			cout << "cannot create thread 2, error code: " << GetLastError() << endl; return 0;
		}
		HANDLE hand[2]; hand[0] = threadhandle1; hand[1] = threadhandle2;
		WaitForMultipleObjects(2, hand, TRUE, INFINITE);
		cout << "In main, sharedvar: " << sharedvar << endl;
		if (sharedvar == 1) break;
		sharedvar = 0;
	}
}