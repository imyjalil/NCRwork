#include "pch.h"
#include<stdio.h>
#include <Windows.h>
#include<tchar.h>
#include<iostream>
using namespace std;

DWORD WINAPI thread_func(LPVOID param)
{
	int i = 0;
	printf("In thread\n");
	for (i = 0; i < 1000; i++)
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
		CREATE_SUSPENDED,  
		&threadid);

	if (threadhandle == NULL)
	{
		printf("unable to create thread \n");
		return 0;
	}
	printf("Thread created\n");
	Sleep(5000);
	printf("Resuming thread\n");
	DWORD res = ResumeThread(threadhandle);
	CloseHandle(threadhandle);
	getchar();
	system("pause");
	return 0;
}