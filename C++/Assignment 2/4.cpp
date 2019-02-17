#include<iostream>
using namespace std;
class Complex
{
	int real;
	int imaginary;
public:
	Complex()
	{
		real = imaginary = 0;
	}
	Complex(int i)
	{
		real = imaginary = i;
	}
	Complex(int i, int j)
	{
		real = i;
		imaginary = j;
	}
	Complex(Complex& c)
	{
		real = c.real;
		imaginary = c.imaginary;
	}
	~Complex()
	{

	}
	void display()
	{
		if (imaginary > 0)
			cout << real << "+i" << imaginary;
		else if(imaginary<0)
			cout << real << "-i" << imaginary;
		else
			cout << real;
		cout << endl;
	}
	Complex operator+(Complex c)
	{
		Complex temp;
		temp.real = real + c.real;
		temp.imaginary = imaginary + c.imaginary;
		return temp;
	}
	Complex operator-(Complex c)
	{
		Complex temp;
		temp.real = real - c.real;
		temp.imaginary = imaginary - c.imaginary;
		return temp;
	}
	Complex operator++()
	{
		real++;
		imaginary++;
		return (*this);
	}
	Complex operator ++(int x)
	{
		Complex temp;
		temp.real = real++;
		temp.imaginary = imaginary++;
		return temp;
	}
	Complex* operator->()
	{
		return this;
	}
	Complex operator,(Complex c)
	{
		return c;
	}
	friend ostream& operator<<(ostream &, Complex);
	friend istream& operator>>(istream &, Complex&);
};

ostream& operator<<(ostream &cout, Complex complex)
{
	if (complex.imaginary > 0)
		cout << complex.real << "+i" << complex.imaginary;
	else if (complex.imaginary < 0)
		cout << complex.real << "-i" << complex.imaginary;
	else
		cout << complex.real;
	return cout;
}

istream& operator>>(istream &cin, Complex& complex)
{
	cout << "Enter real part:";
	cin >> complex.real;
	cout << "Enter imaginary part:";
	cin >> complex.imaginary;
	return cin;
}

int main()
{
	int real, img;
	Complex c1, c2(3), c3, c4, c5, c6,c7(c2);
	cin >> c3;
	cin >> c4;
	c5 = c3 + c4;
	cout << "Sum:" << c5 << endl;
	c6 = (c3 - c4);
	cout << "Diff:" << c6 << endl;
	c5= c2++;
	cout << c5 << endl;
	c6= ++c1;
	c6->display();
	c6 = c5, c2;
	c6->display();
	return 0;
}
