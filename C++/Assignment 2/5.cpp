#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class String
{
	char *sptr;
	int length;
public:
	String()
	{		
	}
	String(const char*sptr, int length)
	{
		this->length = length;
		this->sptr = (char*)calloc(length + 1, sizeof(char));
		strcpy(this->sptr, sptr);
	}
	String(const String &string)
	{
		length = string.length;
		sptr = (char*)calloc(length + 1, sizeof(char));
		strcpy(sptr, string.sptr);
	}
	~String()
	{
		if (sptr != NULL)
			free(sptr);
	}
	String operator+(String s)
	{
		String temp;
		temp.length = length + s.length;
		temp.sptr = (char*)calloc(temp.length + 1, sizeof(char));
		strcpy(temp.sptr, sptr);
		strcat(temp.sptr, s.sptr);
		return temp;
	}
	String operator=(String s)
	{
		length = s.length;
		sptr = (char*)calloc(length + 1, sizeof(char));
		strcpy(sptr, s.sptr);
		return (*this);
	}
	char& operator[](int n)
	{
		return sptr[n];
	}
	friend istream& operator>>(istream&, String&);
	friend ostream& operator<<(ostream&, String);
};
istream& operator>>(istream& cin, String& string)
{
	cout << "Enter string length: ";
	cin >> string.length;
	string.sptr = (char*)calloc(string.length + 1, sizeof(char));
	cout << "Enter string: ";
	cin >> string.sptr;
	return cin;
}
ostream& operator<<(ostream& cout, String string)
{
	cout << "String is: " << string.sptr;
	return cout;
}

int main()
{
	char ch[] = "HELLO";
	String s1, s2(ch, 6), s3(s2),s4;
	cin >> s1;
	s4 = s1 + s2;
	cout << s4 << endl;
	s2[0] = 'X';
	cout << s2 << endl;
	char x = s2[0];
	cout << x << endl;
	return 0;
}
