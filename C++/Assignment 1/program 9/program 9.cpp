#include "pch.h"
#include <iostream>
#include<string>
using namespace std;

class Swap
{
public:
	void val(int a, int b)
	{
		a = a + b;
		b = a - b;
		a = a - b;
	}
	void ref(int &a, int &b)
	{
		a = a + b;
		b = a - b;
		a = a - b;
	}
};

int main()
{
	int n1, n2;
	cout << "Enter two Numbers\n";
	cin >> n1 >> n2;
	cout << "1 - by Value\n2 - by Reference"<<endl;
	int ch;
	cin >> ch;
	Swap obj;
	switch (ch)
	{
	case 1:
		obj.val(n1, n2);
		cout << "value, n1 = " << n1 << " n2 = " << n2 << endl;
		break;
	case 2:
		obj.ref(n1, n2);
		cout << "reference, n1 = " << n1 << " n2 = " << n2 << endl;
		break;
	}
}