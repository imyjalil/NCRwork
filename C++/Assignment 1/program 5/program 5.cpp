#include "pch.h"
#include <iostream>
using namespace std;
class Distance2;
class Distance1
{
	double meter;
	double centimeter;
public:
	void display()
	{
		cout << "Distance: " << meter << " m and " << centimeter << " cm." << endl;
	}
	void set(double a, double b)
	{
		meter = a; centimeter = b;
	}
	double getmeter()
	{
		return meter;
	}
	double getcm()
	{
		return centimeter;
	}
	friend Distance1 add(Distance1, Distance2);
};
class Distance2
{
	double feet;
	double inch;
public:
	void set(double a, double b)
	{
		feet = a; inch = b;
	}
	double getfeet()
	{
		return feet;
	}
	double getinch()
	{
		return inch;
	}
	friend Distance1 add(Distance1, Distance2);
};
Distance1 add(Distance1 d1, Distance2 d2)
{
	Distance1 d3;
	//d3.set(d1.meter + d2.feet*0.3, d1.centimeter + d2.inch*2.5);
	d3.set(d1.getmeter() + d2.feet*0.3,d1.getcm()+d2.inch*2.5);
	return d3;
}
int main()
{
	Distance1 d1, d3; Distance2 d2; double a, b, c, d;
	cout << "Enter meter and cm:" << endl; cin >> a >> b;
	cout << "Enter feet and inch:" << endl; cin >> c >> d;
	d1.set(a, b); d2.set(c, d); d3 = add(d1, d2); d3.display();
}