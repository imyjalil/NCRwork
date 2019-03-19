#include "pch.h"
#include "Header.h"
using namespace std;
int check_validness(string);
int evaluate(string);
int main()
{
	string expression;
	cout << "enter expression" << endl; getline(cin, expression);
	if (!check_validness(expression))
	{
		cout << "Terminating program" << endl;
		return 0;
	}
	int result = evaluate(expression);
	cout << "result: " << result << endl;
	return 0;
}