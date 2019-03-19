#include "pch.h"
#include <iostream>
using namespace std;
class Complex
{
	int real, imag;
public:
	Complex()
	{
		real = 0; imag = 0;
	}
	Complex(int realarg)
	{
		real = realarg; imag = realarg;
	}
	Complex(int realarg, int imagarg)
	{
		real = realarg; imag = imagarg;
	}
	void display()
	{
		cout << "complex no. is " << real ;
		if (imag >= 0)
		{
			cout << "+" << imag << "i" << endl;
		}
		else
		{
			cout << imag << "i" << endl;
		}
	}
	friend Complex add(Complex, Complex);
	friend Complex mul(Complex, Complex);
};
Complex add(Complex c1, Complex c2)
{
	Complex temp;
	temp.real = c2.real + c1.real;
	temp.imag = c2.imag + c1.imag;
	return temp;
}
Complex mul(Complex complex1, Complex complex2)
{
	Complex temp;
	temp.real = (complex1.real * complex2.real)-(complex1.imag*complex2.imag);
	temp.imag = (complex1.imag * complex2.real)+(complex1.real*complex2.imag);
	return temp;
}
int main()
{
	int real, imag;
	cout << "Enter real part for complex number 1" << endl;
	cin >> real;
	cout << "Enter imaginary part for complex number 1" << endl;
	cin >> imag;
	Complex complex1(real, imag);
	cout << "Enter real part for complex number 2" << endl;
	cin >> real;
	cout << "Enter imaginary part for complex number 2" << endl;
	cin >> imag;
	Complex complex2(real, imag), complex3;
	complex3 = add(complex1, complex2);
	complex3.display();
	complex3 = mul(complex1, complex2);
	complex3.display();
}