#include "pch.h"
#include <iostream>
using namespace std;
class Queue
{
	int f, r, *q, size;
public:
	Queue()
	{
		f = -1; r = -1;
	}
	void setsize(int a)
	{
		size = a; q = new int[size];
	}
	void enque(int a)
	{
		if (r == size - 1)
		{
			cout << "queue full" << endl; return;
		}
		if (f == -1 && r == -1)
		{
			f++; r++;
		}
		else
		{
			r++;
		}
		q[r] = a;
	}
	int deque()
	{
		if (f == -1)
		{
			cout << "Queue empty" << endl; return -1;
		}
		if (f == r)
		{
			int ele = q[f]; f = -1; r = -1; return ele;
		}
		else
		{
			return q[f++];
		}
	}
	void display()
	{
		int i; if (f == -1){ cout << "Queue Empty" << endl; return;}
		for (i = f; i <= r; i++) cout << q[i] << " "; cout << endl;
	}
};
int main()
{
	Queue qu; qu.setsize(5); qu.enque(1); qu.enque(2); qu.enque(3); qu.enque(4); qu.enque(5); qu.enque(6); qu.display();
	cout << qu.deque() << endl; cout << qu.deque() << endl; cout << qu.deque() << endl; cout << qu.deque() << endl; cout << qu.deque() << endl;
	qu.display();
}