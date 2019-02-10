#include "pch.h"
#include <iostream>
#define long long ll
using namespace std;
ll int dtob(int dec)
{
	ll int b = 0;
	for (int i = 15; i >= 0; i--)
	{
		int k = dec >> i;
		if (k & 1)
			b = b * 10 + 1;
		else
			b = b * 10 + 0;
	}
		return b;
}
int btod(ll int b)
{
	int dec = 0, count = 0;
	while (b > 0)
	{
		int r = b % 10;
		dec = dec + (r*(int)pow(2, count++));
		b /= 10;
	}
	return dec;
}
void btoh(ll int b)
{

	char hex[1000];
	int dec = btod(b);
	int i = 0;
	while (dec != 0)
	{
		hex[i] = dec % 16;
		dec /= 16;
		i++;
	}
	for (int j = i - 1; j >= 0; j--)
	{
		if (hex[j] > 9)
			cout << (char)(hex[j] + 55);
		else
			cout << hex[j];
	}
	cout << "\n";
}
int main()
{
	int val = 0xCAFE, k;
	ll int b=1;
	ll int temp= 65535;
	temp = val & temp;
	b = dtob(temp);
	ll int val1 = b;
	cout<<"Input in binary notation is: " << val1 << "\n"; 
	int c = 0, c1=1;
	while (val1>0 && c1<=4)
	{
		int r = val1 % 2;
		if (r == 1)
			c++;
		c1++;
		val1 /= 10;
	}
	if (c >= 3)
		cout << "3 of Last four bits are 1's\n";
	else
		cout << "3 of Last four bits are not 1's\n";
	int b1;
	ll int ans=0, ob= b;
	while(b>0)
	{
	    b1 = b % ((int)pow(10, 8));
		ans = (ans*(int)pow(10, 8)) + b1;
		b = b/ ((int)pow(10, 8));
	}
	cout<<"After Inverting byte order:\nbinary value is: " << ans << "\n";
	int deci = btod(ans);
	cout<<"Decimal value is : " << deci << "\nHexadecimal value is : ";
	btoh(ans);
	int nb = 0;
	cout << "\nEnter no. of bits to rotate: ";
	cin >> nb;
	ll int rn = 1;
	ll int nbitVal = ob % ((int)pow(10, nb));
	ob /= ((int)pow(10, nb));
	rn = (nbitVal*(ll int)pow(10, (16- nb))) + ob;
	cout<<"After rotating "<<nb<<" bits\nbinary value is : "<< rn << "\n";
	int deci1 = btod(rn);
	cout << "Decimal value is : " << deci1 << "\nHexadecimal value is : ";
	btoh(rn);
}
