#include "pch.h"
#include <Windows.h>
#include<tchar.h>
#include<iostream>
using namespace std;

DWORD WINAPI thread_func(LPVOID param)
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", i);
		Sleep(1000);
	}
	return 0;
}
int main()
{
	DWORD threadid;
	HANDLE threadhandle;
	threadhandle = CreateThread(
		NULL, 
		0, 
		thread_func,  
		NULL,
		0,
		&threadid);
	if (threadhandle == NULL)
	{
		printf("unable to create thread \n");
		getchar();
		return 0;
	}
	CloseHandle(threadhandle);
	system("pause");
	return 0;
}