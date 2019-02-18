#include "pch.h"
#include<string.h>
#include <iostream>
using namespace std;
class Stack
{
	int top;
	char *s;
	int size;
public:
	Stack()
	{
		top = -1;
	}
	void setsize(int a)
	{
		size = a;
		s = new char[size];
	}
	void push(char a)
	{
		if (isfull())
		{
			cout << "Stack already full" << endl; return;
		}
		s[++top] = a;
	}
	char pop()
	{
		if (isempty()) return -1;
		char a = s[top--];
		return a;
	}
	bool isfull()
	{
		return  (top == size - 1);
	}
	bool isempty()
	{
		return (top == -1);
	}
	char peek()
	{
		if (!isempty()) return s[top];
		return -1;
	}
	void display()
	{
		if (isempty()) {
			cout << "Stack empty" << endl; return;
		}
		for (int i = 0; i <= top; i++) cout << s[i] << " "; cout << endl;
	}
	bool check(char *str)
	{
		int i;
		for (i = 0; i < strlen(str); i++)
		{
			if (str[i] == '[' || str[i] == '(')
			{
				push(str[i]);
			}
			else if (str[i] == ']' || str[i] == ')')
			{
				char c = peek();
				if (c == -1) break;
				if (str[i] == ']')
				{
					if (c == '[')
					{
						pop();
					}
					else
					{
						break;
					}
				}
				else if (str[i] == ')')
				{
					if (c == '(')
					{
						pop();
					}
					else break;
				}
			}
		}
		if (i != strlen(str) || top != -1) return true; return false;
	}
};
int main()
{
	cout << "Enter expression" << endl; char s[100]; cin >> s;
	Stack sta; sta.setsize(strlen(s) + 1);
	if (sta.check(s)) cout << "Unbalanced" << endl;
	else cout << "Balanced" << endl;
}