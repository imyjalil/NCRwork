#include "pch.h"
#include <iostream>
#include<string.h>
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
	int prec(char a)
	{
		if (a == '+' || a == '-') return 1;
		if (a == '*' || a == '/') return 2;
	}
	char * conv(char *str)
	{
		int i = 0, j = 0; char c, c1, *str1; str1 = new char[strlen(str)+1];
		for (i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == '(' || str[i]=='[')
			{
				push(str[i]); //cout << "pushed " << str[i] << endl;
			}
			else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
			{
				c = peek();
				if (!isempty())
				{
					if (c=='(' || c == '[' || (prec(str[i]) > prec(c)))
					{
						push(str[i]); //cout << "pushed if else " << str[i] << endl;
					}
					else
					{
						while (1)
						{
							c1 = pop();
							str1[j++] = c1; //cout << "inserted " << c1 << endl;
							c = peek();
							if (c=='(' || c=='[' || prec(str[i] > prec(c))) break;
						}
						push(str[i]); //cout << "pushed if " << str[i] << endl;
					}
				}
				else
				{
					push(str[i]); //cout << "pushed else " << str[i] << endl;
				}
			}
			else if (str[i] == ')' || str[i]==']')
			{
				while (1)
				{
					if (!isempty())
					{
						c = pop();
						//cout << "popped " << c << endl;
						if ((str[i]==')' && c == '(') || (str[i]==']' && c =='[')) break;
						str1[j++] = c; //cout << "inserted :" << c << endl;
					}
					else break;
				}
			}
			else
			{
				str1[j++] = str[i]; //cout << "inserted ." << str[i] << endl;
			}
		}
		while(1)
		{
			c = pop(); if (c == -1) break;
			str1[j++] = c; //cout << "inserted ," << c << endl;
		}
		str1[j] = '\0'; return str1;
	}
};
int main()
{
	Stack sta; char s[100]; cout << "Enter expression" << endl; cin >> s; sta.setsize(strlen(s) + 1);
	cout <<"postfix notation is "<< sta.conv(s) << endl;
}