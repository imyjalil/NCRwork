#include "pch.h"
#include <iostream>
#include<string.h>
using namespace std;
class Stack
{
	int top;
	int *s;
	int size;
public:
	Stack()
	{
		top = -1;
	}
	void setsize(int a)
	{
		size = a;
		s = new int[size];
	}
	void push(int a)
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
		int a = s[top--];
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
	int prec(char a)
	{
		if (a == '+' || a == '-') return 1;
		if (a == '*' || a == '/') return 2;
	}
	int eval(char *str)
	{
		s = new int[strlen(str) + 1];  int i,j=0,res=0,n[2]; char c, c1;
		//s1 = new char[strlen(str) + 1];
		for (i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*')
			{
				int m = pop(), n = pop();
				if (str[i] == '+')
				{
					res = m + n;
				}
				else if (str[i] == '-')
				{
					res = m - n;
				}
				else if (str[i] == '*')
				{
					res = m * n;
				}
				else if (str[i] == '/')
				{
					res = m / n;
				}
				push(res);
			}
			else
			{
				int n = 0; n = n * 10 + (str[i] - '0');
				while (i + 1 < strlen(str) && str[i + 1] != '@')
				{
					n = n * 10 + (str[i + 1] - '0');
				}
				push(n);
			}
		}
		return pop();
	}
};
int main()
{
	char s[100]; cin >> s; Stack sta; cout << sta.eval(s) << endl;
}