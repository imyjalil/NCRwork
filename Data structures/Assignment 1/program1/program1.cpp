// program1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
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
	int pop()
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
	int peek()
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
};
int main()
{
	Stack sta; cout << "Enter size of stack" << endl; int n; cin >> n;
	sta.setsize(n);
	
	int ch, ele;
	while (1)
	{
		cout << "1.push 2.pop 3.peek 4.display, any other to stop" << endl;
		cin >> ch;
		if (ch <= 0 || ch >= 5) break;
		switch (ch)
		{
		case 1:cout << "Enter element to push" << endl;  cin >> ele; sta.push(ele); break;
		case 2:ele = sta.pop(); if (ele == -1) cout << "Stack empty" << endl; else cout << "Element popped: " << ele << endl; break;
		case 3:ele = sta.peek(); if (ele == -1) cout << "Stack empty" << endl; else cout << "Top element: " << ele << endl; break;
		case 4:sta.display(); break;
		default:break;
		}
	}
}