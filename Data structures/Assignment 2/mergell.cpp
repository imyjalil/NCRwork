#include<iostream>
#include<stdlib.h>
using namespace std;
 
struct Node
{
	int data;
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
 
	void insertbegin(int data)
	{
		struct Node *node = new struct Node;
		node->data = data;
		node->next = start;
		start = node;
	}
 
	void insertend(int data)
	{
		struct Node *node = new struct Node;
		node->data = data;
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
 
	void insertafter(int sele, int ele)
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
 
	void insertbefore(int sele, int ele)
	{
		if (start != NULL)
		{
			struct Node *temp = start;
			if (temp->data == sele)
			{
				struct Node *node = new struct Node;
				node->data = ele;
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
			cout << "LIST IS EMPTY";
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
			cout << endl << "LIST IS EMPTY";
		return data;
	}
	void delete_specific(int ele)
	{
		if (start != NULL)
		{
			struct Node *temp = start;
			if (temp->data == ele)
			{
				start = temp->next;
				delete temp;
			}
			else
			{
				struct Node *prev = temp;
				while (temp->next != NULL)
				{
					if (temp->next->data == ele)
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
			cout << " " << temp->data;
			temp = temp->next;
		}
		cout << endl;
	}
 	LinkedList merge(LinkedList l2)
 	{
 		class LinkedList l3;
 		struct Node* t1, *t2, *t3, *t4;
 		for(t1=start, t2=l2.start;;)
 		{
 			if(t1->data<t2->data)
 			{
 				l3.insertend(t1->data);
 				t1=t1->next;
			}
			else
			{
				l3.insertend(t2->data);
				t2=t2->next;
			}
			if(t1==NULL || t2==NULL) break;
		}
		while(t1!=NULL)
		{
			l3.insertend(t1->data);
			t1=t1->next;
		}
		while(t2!=NULL)
		{
			l3.insertend(t2->data);
			t2=t2->next;
		}
		return l3;
	}
};
 
int main()
{
	LinkedList ll1, ll2, ll3;
	ll1.insertend(50);ll1.insertbegin(10);ll1.insertbefore(50, 20);ll1.insertafter(20, 30);ll1.insertend(60);
	ll1.display();
	ll2.insertbegin(70);ll2.insertafter(70, 95);ll2.insertbefore(70, 45);
	ll2.display();
	ll3=ll1.merge(ll2);
	ll3.display();
	return 0;
}
