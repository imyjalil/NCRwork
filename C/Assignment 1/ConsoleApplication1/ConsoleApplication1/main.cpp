#include<iostream>

using namespace std;
int result = 0;
int add1(int, int);
int sub(int, int);
int mul(int, int);
int divi(int, int);

/*int main()
{
	string s; cin >> s;
	fo
	return 0;
}*/
int main()
{
	int a, b;
	cout << "Enter two numbers\n";
	cin >> a >> b;
	int ch;
	cout << "1-addition\t2-subtraction\t3-Multiplication\t4-Division\n";
	cin >> ch;
	switch (ch)
	{
	case 1: result = add1(a, b);
		cout << "Addition = " << result << endl;
			break;
	case 2: result = sub(a, b);
		cout << "Subtraction = " << result << endl;
			break;
	case 3: result = mul(a, b);
		cout << "Multiplication = " << result << endl;
			break;
	case 4: result = divi(a, b);
		cout << "Division = " << result << endl;
			break;
	}
	system("pause");
	return 0;
}