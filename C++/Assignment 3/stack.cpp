#include <iostream>
using namespace std;

template<class t>

class Stack
{
	t data[5];
	int top;
public:
	Stack()
	{
		top = -1;
	}
	void push();
	void pop();
	void display();
};

template<class t>
void Stack<t>::push()
{
	try
	{
		if (top == 4)
			throw top;
		else
		{
			cout << "Enter Data: " << endl;
			t d;
			cin >> d;
			data[++top] = d;
		}
	}
	catch (int a)
	{
		cout << "Stack OverFlow"<<endl;
	}
}

template<class t>
void Stack<t>::pop()
{
	try
	{
		if (top == -1)
			throw top;
		else
		{
			cout << "Popped "<<data[top--]<<endl;
		}
	}
	catch (int a)
	{
		cout << "Stack UnderFlow"<<endl;
	}
}

template<class t>
void Stack<t>::display()
{
	try
	{
		if (top == -1)
			throw top;
		else
		{
			for (int i = top; i >= 0; i--)
				cout << data[i] << " ";
			cout <<endl;
		}
	}
	catch (int a)
	{
		cout << "Stack Empty"<<endl;
	}
}


int main()
{
	Stack<int >s;
	cout << "Integer"<<endl;
	int flag = 0;
	while (flag!=1)
	{
		cout << "1-push  2-pop  3-display 4-exit"<<endl;
		int c;
		cin >> c;
		switch (c)
		{
			case 1:
				s.push();
				break;
			case 2:
				s.pop();
				break;
			case 3:
				s.display();
				break;
			case 4:
				flag = 1;
				break;
		}
	}
		flag = 0;
		Stack<float >s1;
		cout << "Float"<<endl;
		while (flag!=1)
		{
			cout << "1-push  2-pop  3-display 4-exit"<<endl;;
			int c1;
			cin >> c1;
			switch (c1)
			{
			case 1:
				s1.push();
				break;
			case 2:
				s1.pop();
				break;
			case 3:
				s1.display();
				break;
			case 4:
				flag = 1;
				exit(0);
			}
		}
}
