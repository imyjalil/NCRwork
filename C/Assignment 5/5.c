#include<stdio.h>
struct date
{
	int day, month, year;
};
int main()
{
	long diff = 0;
	struct date date1, date2;
	int i, month[] = { 31, 28,31,30,31,30,31, 31,30, 31, 30,31 };
	long d1, d2, leap, leap2;
	printf("IN YY MM DD, ");
	printf("ENTER YEAR1:\n");
	scanf("%d", &date1.year);
	printf("ENTER MONTH1:\n");
	scanf("%d", &date1.month);
	printf("ENTER DAY1:\n");
	scanf("%d", &date1.day);
	printf("ENTER YEAR2:\n");
	scanf("%d", &date2.year);
	printf("ENTER MONTH2:\n");
	scanf("%d", &date2.month);
	printf("ENTER DAY2:\n");
	scanf("%d", &date2.day);
	d1 = (date1.year - 1) * 365;
	for (i = 0; i < date1.month-1; i++)
	{
		d1 += month[i];
	}
	d1 += date1.day;
	leap = (date1.year) / 4;
	d1 += leap;
	d2 = (date2.year - 1) * 365;
	for (i = 0; i < date2.month - 1; i++)
	{
		d2 += month[i];
	}
	d2 += date2.day;
	leap2 = (date2.year) / 4;
	d2 += leap2;
	diff = d1 - d2;
	diff = diff >= 0 ? diff : -diff;
	printf("Difference: %ld", diff);
	return 0;
}
