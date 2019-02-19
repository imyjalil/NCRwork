#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node*next;
};
class stackll
{
	struct node *start;
	public:
		LL()
		{
			start=NULL;
		}
		void insertbegin(int ele)
		{
			struct node *temp, *t1;temp=new node;
			temp->data=ele;temp->next=NULL;
			if(start==NULL)
			{
				start=temp;
			}
			else
			{
				temp->next=start;start=temp;
			}
		}
		void insertlast(int ele)
		{
			struct node *temp, *t1;temp=new node;
			temp->data=ele;temp->next=NULL;
			if(start==NULL)
			{
				start=temp;
			}
			else
			{
				for(t1=start;t1->next!=NULL;t1=t1->next);
				t1->next=temp;
			}
		}
		void insertafter(int sele,int ele)
		{
			struct node *temp, *t1, *t2;temp=new node;
			temp->data=ele;temp->next=NULL;
			if(start!=NULL)
			{
				for(t1=start;t1!=NULL && t1->data!=sele;t1=t1->next);
				if(t1==NULL)
				{
					cout<<sele<<" does not exist"<<endl;
				}
				else
				{
					if(t1->next==NULL)
					{
						t1->next=temp;
					}
					else
					{
						temp->next=t1->next;t1->next=temp;
					}
				}
			}
		}
		void deletebegin()
		{
			if(start==NULL)
			{
				cout<<"List empty"<<endl;return;
			}
			cout<<"deleted "<<start->data<<endl;
			struct node *temp;temp=start;start=start->next;
			free(temp);
		}
		void deletelast()
		{
			if(start==NULL)
			{
				cout<<"List empty"<<endl;return;
			}
			struct node *t1, *t2;t2=start;
			for(t1=start;t1->next!=NULL;t2=t1, t1=t1->next);
			cout<<"deleted "<<t2->next->data<<endl;t2->next=NULL;
			free(t1);
		}
		void deletebetween(int ele)
		{
			if(start==NULL)
			{
				cout<<"List empty"<<endl;return;
			}
			struct node *t1, *t2;t2=start;
			for(t1=start;t1!=NULL && t1->data!=ele;t2=t1, t1=t1->next);
			if(t1==NULL)
			{
				cout<<ele<<" not found"<<endl;return;
			}
			cout<<"deleted "<<t1->data<<endl;
			t2->next=t1->next;free(t1);
		}
		void displayforward()
		{
			struct node *t1;
			if(start==NULL)
			{
				cout<<"List empty"<<endl;return;
			}
			for(t1=start;t1!=NULL;t1=t1->next) cout<<t1->data<<" ";cout<<endl;
		}
		void displaybackward(struct node* temp)
		{
			if(temp!=NULL)
			{
				displaybackward(temp->next);
				cout<<temp->data<<" ";
			}
		}
		struct node* getstart()
		{
			return start;
		}
		void push(int ele)
		{
			insertbegin(ele);
		}
		void pop()
		{
			if(start==NULL)
			{
				cout<<"stack empty"<<endl;return;
			}
			deletebegin();
		}
};
int main()
{
	class stackll st;st.push(2);st.push(3);st.push(4);st.push(5);st.push(6);st.displayforward();
	st.pop();st.displayforward();
	st.pop();st.displayforward();
	st.pop();st.displayforward();
	st.pop();st.displayforward();
	st.pop();st.displayforward();
	st.pop();
	return 0;
}
