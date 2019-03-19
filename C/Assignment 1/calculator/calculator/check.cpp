#include "pch.h"
#include "Header.h"
using namespace std;
int isdigit(char a)
{
	if (a >= '0' && a <= '9') return 1; return 0;
}
int isoperator(char a)
{
	if (a == '+' || a == '-' || a == '/' || a == '*') return 1; return 0;
}
int isparanthesis(char a)
{
	if (a == '(' || a == ')') return 1;
	return 0;
}
int invalidchar(string expression)
{
	for (int i = 0; i < expression.size(); i++)
	{
		if (!(isdigit(expression[i]) || isoperator(expression[i]) || isparanthesis(expression[i])))
		{
			cout << "Invalid character encountered" << endl;
			return 0;
		}
	}
	return 1;
}
int balancedparanthesis(string expression)
{
	int parancount = 0;
	for (int i = 0; i < expression.size(); i++)
	{
		if (expression[i] == '(') parancount++;
		else if (expression[i] == ')') parancount--;
		if (parancount < 0)
		{
			cout << "Unbalanced paranthesis" << endl;
			return 0;
		}
	}
	if (parancount == 0) return 1;
	cout << "Unbalanced paranthesis" << endl;
	return 0;
}
int extraoperators(string expression)
{
	int testvar = expression.size() - 1;
	while (expression[testvar] == ')')  testvar--; //keep moving left until you don't find a right parenthesis
	if (isoperator(expression[testvar]))
	{
		cout << "Invalid operator at the end " << endl;
		return 0;
	}
	testvar = 0;
	while (expression[testvar] == '(') testvar++; ////keep moving left until you don't find a left parenthesis
	if (expression[testvar] == '*' || expression[testvar] == '/')
	{
		cout << "Invalid operator in the beginning " << endl;
		return 0;
	}
	return 1;
}
int correctparanthesis(string expression)
{
	for (int i = 0; i < expression.size() - 1; i++)//() illegal
	{
		if (expression[i] == '(' && expression[i + 1] == ')')
		{
			cout << "Incorrect parenthesis usage" << endl;
			return 0;
		}
	}
	for (int i = 0; i < expression.size(); i++)//(+*) illegal
	{
		if (expression[i] == '(')
		{
			int testAgainsti = i;
			while (isoperator(expression[i + 1]))
			{
				i++;
			}
			if (testAgainsti != i)
			{
				if (expression[i+1] == ')')
				{
					cout << "Incorrect parenthesis usage" << endl;
					return 0;
				}
			}
		}
	}
	return 1;
}
int operatorbeforeparanthesisending(string expression)
{
	for (int i = 0; i < expression.size()-1; i++)
	{
		if (isoperator(expression[i]))
		{
			if (expression[i + 1] == ')')
			{
				cout << "operator before closing parenthesis" << endl; return 0;
			}
		}
	}
	return 1;
}
int invalidoperation(string expression)//checks for contiguous multiple operators
{
	int opcnt = 0;
	for (int i = 0; i < expression.size(); i++)
	{
		if (isoperator(expression[i]))
		{
			while (i < expression.size() && isoperator(expression[i]))
			{
				opcnt++; i++;
			}
			if (opcnt==1 || (opcnt == 2 && (expression[i - 1] == '-' || expression[i-1] == '+')))
			{
				//do nothing
			}
			else
			{
				cout << "Invalid operator usage" << endl;
				return 0;
			}
		}
		opcnt = 0;
	}
}
int invalidoperators(string expression)
{
	int i;
	for (i = 0; i < expression.size() - 1; i++)
	{
		if (isdigit(expression[i]))
		{
			if (expression[i + 1] == '(')
			{
				cout << "Invalid operator usage" << endl;
				return 0;
			}
		}
	}
	return 1;
}
int check_validness(string expression)
{
	if (!invalidchar(expression)) return 0;
	if (!balancedparanthesis(expression)) return 0;
	if (!correctparanthesis(expression)) return 0;
	if (!extraoperators(expression)) return 0;
	if (!operatorbeforeparanthesisending(expression)) return 0;
	if (!invalidoperation(expression)) return 0;
	if (!invalidoperators(expression)) return 0;
	return 1;
}