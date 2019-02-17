#include<stdio.h>
#define fun(x) printf("%s","HELLO "##x)
int main()
{
#define x "abc"
#ifdef x
	fun(x);
#endif
	return 0;
}
