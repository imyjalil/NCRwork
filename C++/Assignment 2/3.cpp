#include<iostream>
#include<string.h>
using namespace std;
class Employee
{
	int empno, salary;
	char name[30];
public:
	Employee()
	{
		empno = 0;
		strcpy(name, "");
		salary = 0;
	}
	Employee(int empno, char *name, int salary)
	{
		this->empno = empno;
		int name_length = strlen(name);
		strcpy(this->name, name);
		this->salary = salary;
	}
	void set_empno(int empno)
	{
		this->empno = empno;
	}
	int get_empno()
	{
		return empno;
	}
	void set_salary(int salary)
	{
		this->salary = salary;
	}
	int get_salary()
	{
		return salary;
	}
	void set_name(const char* name)
	{
		int name_length = strlen(name);
		strcpy(this->name, name);
	}
	char* get_name()
	{
		int name_length = strlen(this->name);
		char name[30];
		strcpy(name, this->name);
		return name;
	}
	~Employee()
	{
		if (name != NULL)
		{
			delete name;
		}
	}
	friend istream& operator>>(istream&, Employee&);
};

istream& operator>>(istream& cin, Employee& emp)
{
	cout << "Enter empno : ";
	cin >> emp.empno;
	cout << "Enter name:";
	cin >> emp.name;
	cout << "Enter salary:";
	cin >> emp.salary;
	return cin;
}

int main()
{
	Employee *emp;int i;
	emp = new Employee[5];
	cout << "Enter 5 employee details";
	for (i = 0; i < 5; i++)
	{
		cout << "Enter employee " << i + 1 << " details" << endl;
		cin >> emp[i];
	}
	return 0;
}
