// CMD APP.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "CmdApp.h"
#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

class CmdApp
{
	NODE *head, *current;

public:
	CmdApp()
	{
		head = new NODE;
		current = head;
		head->name = "C";
		head->parent = NULL;
		head->directory_flag = true;
		head->children = NULL;
		head->sibling = NULL;
	}

	CMDAPP_API void clear_screen()
	{
		system("CLS");
		//pwd();
	}


	CMDAPP_API NODE insert_file(string fileName)
	{

	}

	CMDAPP_API void delete_file(string fileName)
	{
		if (fileName == "/")
		{
			cout << "Access Denied" << endl;
			return;
		}

	}
};