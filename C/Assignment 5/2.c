#include<stdio.h>
#include<stdlib.h>
struct s1
{
	int a;
	char b;
};
union  u1
{
	int a;
	char b;
};
int main()
{
	struct s1 s;
	union u1 u;
	printf("Size of structure: %d\n", sizeof(s));
	printf("Size of union: %d\n", sizeof(u));
	return 0;
}
