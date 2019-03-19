/*Define a template stack class. Using this template class, create stack objects of int,
float, char* and complex type. Include exception-handling functionality.*/
#include "pch.h"
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class Complex
{
	int real, img;
public:
	Complex(int realarg, int imgarg)
	{
		real = realarg;
		img = imgarg;
	}
};
template <typename T>
class Stack
{
	T *pointer;
	int size, top;
public:
	Stack()
	{
		size = 0; top = -1;
	}
	void setSize(int sizearg)
	{
		size = sizearg;
		pointer = new T[size];
	}
	int isfull()
	{
		if (top == size - 1)
		{
			return 1;
		}
		return 0;
	}
	int isempty()
	{
		if (top == -1)
		{
			return 1;
		}
		return 0;
	}
	void push(T element)
	{
		pointer[++top] = element;
	}
	T pop()
	{
		return pointer[top--];
	}
	T peek()
	{
		return pointer[top];
	}
	void display()
	{
		if (isempty())
		{
			cout << "stack empty" << endl;
			return;
		}
		for (int i = top; i >= 0; i--)
		{
			cout << pointer[i] << " ";
		}
		cout << endl;
	}
};
int main()
{
	Stack<int> intstack;
	Stack<char *> charstack;
	Stack<float> floatstack;
	Stack<Complex> complexstack;
	cout << "Enter stack size" << endl;
	int size; cin >> size; intstack.setSize(size);
	cout << "Integer stack" << endl;
	while (1)
	{
		cout << "1 push, 2 pop, 3 peek, 4 display 5 break" << endl;
		int innerchoice; cin >> innerchoice;
		if (innerchoice == 1)
		{
			if (intstack.isfull())
			{
				cout << "Stack already full" << endl; continue;
			}
			cout << "Enter element to insert" << endl;
			int element; cin >> element; intstack.push(element);
		}
		else if (innerchoice == 2)
		{
			if (intstack.isempty())
			{
				cout << "stack empty" << endl; continue;
			}
			cout << intstack.pop() << " popped" << endl;
		}
		else if (innerchoice == 3)
		{
			if (intstack.isempty())
			{
				cout << "stack empty" << endl; continue;
			}
			cout << intstack.peek() << endl;
		}
		else if (innerchoice == 4)
		{
			intstack.display();
		}
		else if (innerchoice == 5)
		{
			break;
		}
		else
		{
			cout << "Enter valid choice" << endl;
			continue;
		}
	}
	cout << "Float stack" << endl;
	cout << "Enter stack size" << endl;
	cin >> size; floatstack.setSize(size);
	while (1)
	{
		cout << "1 push, 2 pop, 3 peek, 4 display 5 break" << endl;
		int innerchoice; cin >> innerchoice;
		if (innerchoice == 1)
		{
			if (floatstack.isfull())
			{
				cout << "Stack already full" << endl; continue;
			}
			cout << "Enter element to insert" << endl;
			float element; cin >> element; floatstack.push(element);
		}
		else if (innerchoice == 2)
		{
			if (floatstack.isempty())
			{
				cout << "stack empty" << endl; continue;
			}
			cout << floatstack.pop() << " popped" << endl;
		}
		else if (innerchoice == 3)
		{
			if (floatstack.isempty())
			{
				cout << "stack empty" << endl; continue;
			}
			cout << floatstack.peek() << endl;
		}
		else if (innerchoice == 4)
		{
			floatstack.display();
		}
		else if (innerchoice == 5)
		{
			break;
		}
		else
		{
			cout << "Enter valid choice" << endl;
			continue;
		}
	}
	cout << "char* stack" << endl;
	cout << "Enter stack size" << endl;
	cin >> size; charstack.setSize(size);
	while (1)
	{
		cout << "1 push, 2 pop, 3 peek, 4 display 5 break" << endl;
		int innerchoice; cin >> innerchoice;
		if (innerchoice == 1)
		{
			if (charstack.isfull())
			{
				cout << "Stack already full" << endl; continue;
			}
			cout << "Enter element to insert" << endl;
			char* element; element = (char *)malloc(100 * sizeof(char)); cin >> element; charstack.push(element); free(element);
		}
		else if (innerchoice == 2)
		{
			if (charstack.isempty())
			{
				cout << "stack empty" << endl; continue;
			}
			cout << charstack.pop() << " popped" << endl;
		}
		else if (innerchoice == 3)
		{
			if (charstack.isempty())
			{
				cout << "stack empty" << endl; continue;
			}
			cout << charstack.peek() << endl;
		}
		else if (innerchoice == 4)
		{
			charstack.display();
		}
		else if (innerchoice == 5)
		{
			break;
		}
		else
		{
			cout << "Enter valid choice" << endl;
			continue;
		}
	}
	return 0;
}