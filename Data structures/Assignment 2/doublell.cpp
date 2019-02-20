#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node* prev;
	struct node* next;
};
class Dll
{
	struct node *start;
	public:
		DLL()
		{
			start=NULL;
		}
		void insertbegin(int ele)
		{
			struct node* temp;temp=new node;
			temp->data=ele;temp->prev=NULL;temp->next=NULL;
			if(start==NULL)
			{
				start=temp;return;
			}
			temp->next=start;start->prev=temp;start=temp;
		}
		void insertend(int ele)
		{
			struct node* temp, *t1;temp=new node;
			temp->data=ele;temp->prev=NULL;temp->next=NULL;
			if(start==NULL)
			{
				start=temp;return;
			}
			for(t1=start;t1->next!=NULL;t1=t1->next);
			t1->next=temp;temp->prev=t1;
		}
		void insertafter(int sele, int ele)
		{
			struct node* temp, *t1;temp=new node;
			temp->data=ele;temp->prev=NULL;temp->next=NULL;
			for(t1=start;t1!=NULL && t1->data != sele;t1=t1->next);
			if(t1==NULL)
			{
				cout<<ele<<" not found"<<endl;return;
			}
			if(t1->next==NULL)
			{
				t1->next=temp;temp->prev=t1;
			}
			temp->next=t1->next;t1->next->prev=temp;temp->prev=t1;t1->next=temp;
		}
		void displayforward()
		{
			struct node* t1;
			for(t1=start;t1!=NULL;t1=t1->next)
			{
				cout<<t1->data<<" ";
			}
			cout<<endl;
		}
		void displaybackward()
		{
			struct node* t1;
			for(t1=start;t1->next!=NULL;t1=t1->next);
			for(;t1!=NULL;t1=t1->prev)
			{
				cout<<t1->data<<" ";
			}
			cout<<endl;
		}
		void deletefirst()
		{
			cout<<start->data<<" deleted"<<endl;
			struct node* t1=start;start=start->next;start->prev=NULL;
			free(t1);
		}
		void deleteend()
		{
			struct node* t1, *temp;
			for(t1=start;t1->next!=NULL;t1=t1->next);
			cout<<t1->data<<" deleted"<<endl;
			temp=t1;
			t1->prev->next=NULL;free(temp);
		}
		void deletebetween(int ele)
		{
			struct node* t1, *temp;
			for(t1=start;t1!=NULL && t1->data!=ele;t1=t1->next);
			if(t1==NULL)
			{
				cout<<ele<<" not found"<<endl;return;
			}
			temp=t1;cout<<t1->data<<" deleted"<<endl;
			if(t1==start)
			{
				//cout<<"start"<<endl;
				start=start->next;start->prev=NULL;
				//cout<<"exit"<<endl;
			}
			else if(t1->next==NULL)
			{
				t1->prev->next=NULL;
			}
			else
			{
				t1->next->prev=t1->prev;t1->prev->next=t1->next;
			}
			free(temp);
			//cout<<"exited"<<endl;
		}
};
int main()
{
	class Dll d;d.insertbegin(8);d.insertbegin(7);d.insertbegin(9);d.insertbegin(3);d.insertend(4);d.insertafter(3,5);d.displayforward();d.displaybackward();
	d.deletebetween(9);d.displayforward();
}
