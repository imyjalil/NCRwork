#include "pch.h"
#include <iostream>
#include<Windows.h>
using namespace std;
int main()
{
	HANDLE event = CreateEvent(
		NULL,
		FALSE,
		FALSE,
		TEXT("Event 1")
	);
	system("pause");
}