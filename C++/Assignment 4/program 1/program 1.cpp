#include "pch.h"
#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node* next;
	struct node *prev;
};
class Deque
{
	struct node* front, *rear;
public:
	Deque()
	{
		front = NULL; rear = NULL;
	}
	void insert_front(int element)
	{
		struct node* newnode = new node;
		newnode->data = element;
		newnode->next = NULL;
		newnode->prev = NULL;
		if (front == NULL)
		{
			front = newnode; rear = newnode;
		}
		else
		{
			newnode->next = front;
			front->prev = newnode;
			front = newnode;
		}
	}
	void insert_rear(int element)
	{
		struct node* newnode = new node;
		newnode->data = element;
		newnode->next = NULL;
		newnode->prev = NULL;
		if (front == NULL)
		{
			front = newnode; rear = newnode;
		}
		else
		{
			rear->next = newnode;
			newnode->prev = rear;
			rear = newnode;
		}
	}
	void delete_front()
	{
		if (front == NULL)
		{
			cout << "Empty deque" << endl;
			return;
		}
		cout << "deleting " << front->data << endl;
		struct node *temp = front;
		front = front->next;
		if (front == NULL)
		{
			rear = NULL;
		}
		else
		{
			front->prev = NULL;
		}
		delete temp;
	}
	void delete_rear()
	{
		if (front == NULL)
		{
			cout << "Empty deque" << endl;
			return;
		}
		cout << "deleting " << rear->data << endl;
		struct node *temp = rear;
		rear = rear->prev;
		if (rear == NULL)
		{
			front = NULL;
		}
		else
		{
			rear->next = NULL;
		}
		delete temp;
	}
	void display()
	{
		if (front == NULL)
		{
			cout << "Empty deque" << endl; return;
		}
		struct node* temp;
		for (temp = front; temp != NULL; temp = temp->next)
		{
			cout << temp->data << " ";
		}
		cout << endl;
	}
	~Deque()
	{
		cout << "In deque destructor" << endl;
		struct node *temp, *temp1;
		temp = rear; temp1 = temp; if (temp != NULL) temp = temp->prev;
		for (; temp != NULL; temp = temp->prev)
		{
			delete temp1;
			temp1 = temp;
		}
	}
};
class Stack: public Deque
{
public:
	void push(int element)
	{
		insert_front(element);
	}
	void pop()
	{
		delete_front();
	}
	~Stack()
	{
		cout << "in stack destructor" << endl;
	}
};
class Queue : public Deque
{
public:
	void insert(int element)
	{
		insert_rear(element);
	}
	void delet()
	{
		delete_front();
	}
	~Queue()
	{
		cout << "In queue destructor" << endl;
	}
};
int main()
{
	cout << "Stack:" << endl;
	Stack stack;
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.display();
	/*stack.pop();
	stack.pop();
	stack.pop();*/
	stack.display();
	stack.pop();
	cout << "Queue:" << endl;
	Queue queue;
	queue.insert(1);
	queue.insert(2);
	queue.insert(3);
	queue.insert(4);
	queue.display();
	/*queue.delet();
	queue.delet();
	queue.delet();
	queue.delet();
	queue.delet();*/
}