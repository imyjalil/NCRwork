#include<stdio.h>
struct time
{
	int h, m, s;
};
int main()
{
	struct time ti;
	printf("ENTER HOURS:\n");
	scanf("%d", &ti.h);
	printf("ENTER MINUTES:\n");
	scanf("%d", &ti.m);
	printf("ENTER SECONDS:\n");
	scanf("%d", &ti.s);
	printf("TIME OF THE DAY :: %d : %d : %d (HH: MM : SS)", ti.h, ti.m, ti.s);
	return 0;
}
