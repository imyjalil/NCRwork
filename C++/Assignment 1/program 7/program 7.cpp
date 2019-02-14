#include "pch.h"
#include <iostream>
#include<string>
using namespace std;

class Mat
{
	int a[10][10], v[10], ans[10] = {0}, m, n;
public:
	Mat(int m, int n)
	{
		this->m = m;
		this->n = n;
		cout << "Enter Matrix"<<endl;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
			}
		}
		cout << "Enter a Vector"<<endl;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
	}
	friend void Multiply(Mat);
};

void Multiply(Mat ob)
{
	cout << "After Multiplication"<<endl;
	for (int i = 0; i < ob.m; i++)
	{
		for (int j = 0; j < ob.n; j++)
		{
			ob.ans[i] += ob.a[i][j] * ob.v[j];
		}
		cout << ob.ans[i] << endl;
	}
}

int main()
{
	int m, n;
	cout << "Enter size of matrix: ";
	cin >> m >> n;
	Mat ob(m, n);
	Multiply(ob);
}