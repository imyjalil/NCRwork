#include<stack>
#include <iostream>
#include<string>
using namespace std;
stack<int >s;
void eval(string str)
{
	int i, n;
	for (i = 0; i < str.length();i++)
	{
		if(str[i]>='0' && str[i]<='9')
		{
			n = 0;
			while (str[i] != '@')
			{
				n = n * 10 + (str[i] - '0');
				i++;
			}
			s.push(n);
		}
		else
		{
			int a=-1, b=-1;
			if (!s.empty())
			{
				a = s.top();
				s.pop();
			}
			if (!s.empty())
			{
				b = s.top();
				s.pop();
			}
			if (a != -1 && b != -1)
			{
				int ans;
				switch (str[i])
				{
				case '+':
					ans = b + a;
					break;
				case '-':
					ans = b - a;
					break;
				case '*':
					ans = b * a;
					break;
				case '/':
					ans = b / a;
					break;
				}
				s.push(ans);
			}
		}
	}
	cout << s.top()<<"\n";
}

int main()
{
	string pf;
	getline(cin, pf);
	eval(pf);
}
