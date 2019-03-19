#include "pch.h"
#include<iostream>
#include<stdlib.h>
#include<windows.h>
using namespace std;
int main(int argc, CHAR *argv[])
{
	//GetCommandLine()
	/*
	LPWSTR args;
	int numargs, i;
	args = GetCommandLine();
	if (args == NULL)
	{
		cout << "Failed" << endl;
	}
	else
	{
		wcout << args << endl;
	}
	*/
	//CommandLineToArgvW
	/*
	LPWSTR *args;
	int numargs, i;
	args = CommandLineToArgvW(GetCommandLine(), &numargs);
	if(args ==NULL)
	{
	cout<<"Failed"<<endl;
	}
	else
	{
		for(i=0;i<numargs;i++)
		{
			wcout << i << ":" << args[i] << endl;
		}
	}
	*/
	//ExpandEnvironmentStrings
	//free(args);
	return 0;
}