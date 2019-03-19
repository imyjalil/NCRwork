#include "pch.h"
#include "Header.h"
#include<stack>
using namespace std;
int isoperator(char);
string removeextraneousparenthesis(string expression)//(33)->33
{
	for (int i = 0; i < expression.size(); i++)
	{
		if (expression[i] == '(')
		{
			int testAgainsti = i;
			while (isdigit(expression[i + 1]))
			{
				i++;
			}
			if (testAgainsti != i)
			{
				if (expression[i + 1] == ')')
				{
					expression.erase(testAgainsti, 1);
					expression.erase(i, 1);
					i -= 2;
				}
			}
		}
	}
	return expression;
}
int prec(char c)
{
	if (c == '*' || c == '/') return 2;
	if (c == '+' || c == '-') return 1;
	return 0;
}
int opera(int a, int b, char oper)//arithmetic evaluation
{
	if (oper == '*')
	{
		return a * b;
	}
	else if (oper == '/')
	{
		if (b == 0)
		{
			cout << "Division by zero exception" << endl;
			exit(1);
		}
		return a / b;
	}
	else if (oper == '+')
	{
		return a + b;
	}
	else if (oper == '-')
	{
		return a - b;
	}
}
int evaluate(string expression)
{
	int i = 0; 
	stack<int> val; //operand stack
	stack<char> op; //operator stack
	expression = removeextraneousparenthesis(expression);
	for (i = 0; i < expression.size(); i++)
	{
		if (expression[i] == '(')//left paranthesis, push it onto operator stack
		{
			op.push(expression[i]);
		}
		else if (isdigit(expression[i]))//number, push it onto operand stack
		{
			int res = 0;
			while (i < expression.size() && isdigit(expression[i]))
			{
				res = (res * 10) + (expression[i] - '0');
				i++;
			}
			i--;
			val.push(res);
		}
		else if (expression[i] == ')')//pop until ( is encountered, for every operator popped, pop two operands
		{
			while (!op.empty() && op.top() != '(')
			{
				int popval1 = val.top();
				val.pop();
				int popval2 = val.top();
				val.pop();
				char oper = op.top();
				op.pop();
				int popres = opera(popval2, popval1, oper);
				val.push(popres);
			}
			op.pop();
		}
		else if (isoperator(expression[i]))
		{
			if (expression[i] == '-')//negative integer case
			{
				if (i == 0 || isoperator(expression[i - 1]) || expression[i - 1] == '(')
				{
					int res = 0; i++;
					while (i < expression.size() && isdigit(expression[i]))
					{
						res = res * 10 + (expression[i] - '0');
						i++;
					}
					val.push(res*(-1)); 
					i--;
					continue;
				}
			}
			else if (expression[i]=='+')//positive integer case
			{
				if (i == 0 || isoperator(expression[i - 1]) || expression[i - 1] == '(')
				{
					int res = 0; i++;
					while (i < expression.size() && isdigit(expression[i]))
					{
						res = res * 10 + (expression[i] - '0');
						i++;
					}
					val.push(res);
					i--;
					continue;
				}
			}
			while (!op.empty() && prec(op.top()) >= prec(expression[i]))//rest cases
			{
				int popval2 = val.top();
				val.pop();
				int popval1 = val.top();
				val.pop();
				char oper = op.top();
				op.pop();
				int popres = opera(popval1, popval2, oper);
				val.push(popres);
			}
			op.push(expression[i]);
		}
	}
	while (!op.empty())//after expression is scanned, empty the stacks
	{
		int popval2 = val.top();
		val.pop();
		int popval1 = val.top();
		val.pop();
		char oper = op.top();
		op.pop();
		int popres = opera(popval1, popval2, oper);
		val.push(popres);
	}
	return val.top();
}