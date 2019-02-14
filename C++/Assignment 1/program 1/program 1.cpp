// program 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
class Time
{
	int h, m, s;
	public:
	Time()
	{
		h = 0; m = 0; s = 0;
	}
	Time(int ho, int mo, int so)
	{
		h = ho; m = mo; s = so;
	}
	void display()
	{
		cout << h << ":" << m << ":" << s << endl;
	}
	Time addTime(Time t1, Time t2)
	{
		Time t3;
		t3.h = t1.h + t2.h;
		t3.m = t1.m + t2.m;
		t3.s = t1.s + t2.s;
		return t3;
	}
};
int main()
{
	Time t1; Time t2(11, 43, 34);
	Time t3 = t3.addTime(t1, t2);
	t3.display();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
