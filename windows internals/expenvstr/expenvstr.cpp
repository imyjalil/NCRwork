#include "pch.h"
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<tchar.h>
using namespace std;

void DumpEnvStrings(TCHAR *env[])
{
	/*int current = 0;
	PTSTR *pElement = (PTSTR *)env;
	PTSTR pCurrent = NULL;
	while (pElement != NULL)
	{
		pCurrent = (PTSTR)(*pElement);
		if (pCurrent == NULL)
		{
			pElement = NULL;
		}
		else
		{
			_tprintf(TEXT("[%u] %s\r\n"), current, pCurrent);
			current++;
			pElement++;
		}
	}*/
	TCHAR **temp1 = env; int c = 0;
	while (*temp1 != NULL)
	{
		c++;
		_tprintf(TEXT("%d - %s\n"), c, *temp1);
		//cout << temp1 << " " << *temp1 << " " << wcslen(*temp1) << endl;
		(temp1)++;
	}
}
int _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	DumpEnvStrings(env);
	TCHAR envVarString[] = TEXT("%SystemRoot%");
	//TCHAR envVarString[] = TEXT("%SystemRoot%");
	TCHAR buffer[MAX_PATH];
	DWORD ret;
	ret = ExpandEnvironmentStrings(envVarString, buffer, MAX_PATH);
	if (!ret)
	{
		printf("%d\n", GetLastError());
		getchar();
		return 0;
	}
	//printf("%S\n", buffer);
}