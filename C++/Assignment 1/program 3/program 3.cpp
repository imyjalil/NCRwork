// program 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
class Complex
{
	int r, i;
public:
	Complex()
	{
		r = 0; i = 0;
	}
	Complex(int re)
	{
		r = re; i = re;
	}
	Complex(int re, int im)
	{
		r = re; i = im;
	}
	void display()
	{
		cout << "real=" << r << endl;
		cout << "img=" << i << endl;
	}
	friend Complex add(Complex, Complex);
	friend Complex mul(Complex, Complex);
};
Complex add(Complex c1, Complex c2)
{
	Complex temp;
	temp.r = c2.r + c1.r;
	temp.i = c2.i + c1.i;
	return temp;
}
Complex mul(Complex c1, Complex c2)
{
	Complex temp;
	temp.r = c1.r * c2.r;
	temp.i = c1.i * c2.i;
	return temp;
}
int main()
{
	Complex c1(2, 3), c2(4, 5), c3;
	c3 = add(c1,c2);
	c3.display();
	c3 = mul(c1,c2);
	c3.display();
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