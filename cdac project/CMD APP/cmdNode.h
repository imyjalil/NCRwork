#pragma once


#ifndef __CMDNODE_h__
#define __CMDNODE_h__

#include<iostream>
#include<string>
using namespace std;
struct Node
{
	string name;
	bool directory_flag;
	Node *children;
	Node *sibling;
	Node *parent;
};
typedef struct Node NODE;
#endif