#include<iostream>
#include<stdlib.h> 
using namespace std;
struct Node
{
	int data;
	int power;
	struct Node*next;
};
 
class LinkedList
{
	struct Node *start;
public:
	LinkedList()
	{
		start = NULL;
	}
 
	struct Node *getStart()
	{
		return start;
	}
 
	void insertbegin(int data,int power)
	{
		struct Node *node = new struct Node;
		node->data = data;
		node->power = power;
		node->next = start;
		start = node;
	}
 
	void insertend(int data,int power)
	{
		struct Node *node = new struct Node;
		node->data = data;
		node->power = power;
		node->next = NULL;
		if (start != NULL)
		{
			struct Node *temp = start;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = node;
		}
		else
		{
			start = node;
		}
	}
 
	void insertafter(int sele, int ele,int power)
	{
		if (start != NULL)
		{
			struct Node *temp = start;
			while (temp != NULL)
			{
				if (temp->data == sele)
					break;
				temp = temp->next;
			}
			if (temp != NULL)
			{
				struct Node *node = new struct Node;
				node->data = ele;
				node->power = power;
				node->next = temp->next;
				temp->next = node;
			}
			else
			{
				cout << endl << "ELEMENT NOT FOUND";
			}
		}
		else
		{
			cout << endl << "EMPTY LIST";
		}
	}
 
	void insertbefore(int sele, int ele,int power)
	{
		if (start != NULL)
		{
			struct Node *temp = start;
			if (temp->data == sele)
			{
				struct Node *node = new struct Node;
				node->data = ele;
				node->power = power;
				node->next = start;
				start = node;
			}
			else
			{
				while (temp->next != NULL)
				{
					if (temp->next->data == sele)
						break;
					temp = temp->next;
				}
				if (temp->next != NULL)
				{
					struct Node *node = new struct Node;
					node->data = ele;
					node->power = power;
					node->next = temp->next;
					temp->next = node;
				}
				else
				{
					cout << endl << "ELEMENT NOT FOUND";
				}
			}
		}
		else
		{
			cout << endl << "EMPTY LIST";
		}
	}
 
	int delete_first()
	{
		int data = -999;
		if (start != NULL)
		{
			struct Node *temp = start;
			start = temp->next;
			data = temp->data;
			delete temp;
		}
		else
		{
			cout << "LIST EMPTY";
		}
		return data;
	}
 
	int delete_last()
	{
		int data = -999;
		if (start != NULL)
		{
			struct Node *temp = start;
			if (temp->next == NULL)
				delete_first();
			else
			{
				while (temp->next->next != NULL)
				{
					temp = temp->next;
				}
				data = temp->next->data;
				delete temp->next;
				temp->next = NULL;
			}
		}
		else
			cout << endl << "LIST EMPTY";
		return data;
	}
 
	void delete_specific(int ele,int power)
	{
		if (start != NULL)
		{
			struct Node *temp = start;
			if (temp->data == ele && temp->power == power)
			{
				start = temp->next;
				delete temp;
			}
			else
			{
				struct Node *prev = temp;
				while (temp->next != NULL)
				{
					if (temp->next->data == ele && temp->power == power)
						break;
					temp = temp->next;
				}
				if (temp->next != NULL)
				{
					struct Node *temp1 = temp->next;
					temp->next = temp1->next;
					delete temp1;
				}
				else
				{
					cout << endl << ele << " NOT FOUND";
				}
			}
		}
		else
			cout << endl << "LIST IS EMPTY";
	}
 
	void display()
	{
		struct Node *temp = start;
		while (temp != NULL)
		{
			cout << " " << temp->data << ":" << temp->power;
			temp = temp->next;
		}
		cout << endl;
	}
 
	LinkedList add(LinkedList l)
	{
		LinkedList ll3;
		struct Node *temp1 = l.getStart(), *temp2 = start;
		while (temp1 != NULL && temp2 != NULL)
		{
			if (temp1->power > temp2->power)
			{
				ll3.insertend(temp1->data,temp1->power);
				temp1 = temp1->next;				
			}
			else if (temp1->power < temp2->power)
			{
				ll3.insertend(temp2->data, temp2->power);
				temp2 = temp2->next;
			}
			else
			{
				ll3.insertend(temp1->data + temp2->data, temp1->power);
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
		}
		while (temp1 != NULL)
		{
			ll3.insertend(temp1->data, temp1->power);
			temp1 = temp1->next;
		}
		while (temp2 != NULL)
		{
			ll3.insertend(temp2->data, temp1->power);
			temp2 = temp2->next;
		}
		return ll3;
	}
};
 
int main()
{
	LinkedList ll1, ll2, ll3;
	ll1.insertend(50,2);
	ll1.insertbegin(10,5);
	ll1.insertbefore(10, 20,6);
	ll1.insertafter(10, 30,3);
	ll1.insertend(40,1);
	ll2.insertbegin(70,4);
	ll2.insertafter(70, 95,1);
	ll2.insertbefore(70, 45,5);
	ll1.display();
	ll2.display();
	ll3 = ll1.add(ll2);
	ll3.display();
	return 0;
}
