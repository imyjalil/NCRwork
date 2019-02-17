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
	friend ostream& operator<<(ostream&, String);
};
ostream& operator<<(ostream& cout, String string)
{
	cout << "String is: " << string.sptr;
	return cout;
}
int main()
{
	char ch[] = "HELLO";
	String s1(ch, 6), s3(s1);
	cout << s3;
	return 0;
}
