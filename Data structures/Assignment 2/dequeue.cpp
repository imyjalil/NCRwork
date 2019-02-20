#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class Deq
{
	int *arr,f,r,size;
	public:
	Deq(int a)
	{
		size=a;arr=new int[size];f=-1;r=-1;
	}
	void insertbegin(int);void insertend(int);void deletebegin();void deleteend();void display();	
};
void Deq::insertbegin(int ele)
{
	if(f==r-1 || f==size-1)
	{
		cout<<"Queue full"<<endl;return;
	}
	arr[++f]=ele;
}
void Deq::insertend(int ele)
{
	if(r==0 || r==f+1)
	{
		cout<<"Queue full"<<endl;return;
	}
	if(r==-1)
	{
		r=size-1;arr[r]=ele;return;
	}
	arr[--r]=ele;
}
void Deq::deletebegin()
{
	if(f==-1)
	{
		cout<<"queue empty"<<endl;return;
	}
	cout<<arr[f--]<<" deleted"<<endl;
}
void Deq::deleteend()
{
	if(r==-1)
	{
		cout<<"queue empty"<<endl;return;
	}
	if(r==size-1)
	{
		cout<<arr[r]<<" deleted"<<endl;r=-1;return;
	}
	cout<<arr[r++]<<" deleted"<<endl;
}	
void Deq::display()
{
	if(f==-1 && r==-1)
	{
		cout<<"Empty queue"<<endl;return;
	}
	int i;
	//cout<<"f="<<f<<" r="<<r<<endl;
	if(f!=-1) for(i=0;i<=f;i++) cout<<arr[i]<<" ";
	if(r!=-1) for(i=size-1;i>=r;i--) cout<<arr[i]<<" ";cout<<endl;
}
int main()
{
	Deq d(5);d.insertbegin(5);d.display();
	d.insertbegin(10);d.display();
	d.insertend(25);d.display();
	d.insertend(30);d.display();
	d.deletebegin();d.display();
	d.deleteend();d.display();
	d.deletebegin();d.display();
	d.deleteend();d.display();
	d.insertend(35);d.display();
	d.insertbegin(45);d.display();
	return 0;
}

