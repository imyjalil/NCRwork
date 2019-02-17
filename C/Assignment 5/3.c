#include<stdio.h>
enum operators { addition = 1 ,subtraction,multiplication };
struct complex
{
	double real;
	double imag;
};
int main()
{
	struct  complex complex1, complex2;
	int choice;
	double realsum = 0, realdiff = 0, realproduct = 1, imagsum = 0, imagdiff = 0, imagproduct = 1, resproduct = 0;
	printf("Enter real part of 1st no.:");
	scanf("%lf", &complex1.real);
	printf("Enter imaginary part of 1st no.:");
	scanf("%lf", &complex1.imag);
	printf("Enter real part of 2nd no.:");
	scanf("%lf", &complex2.real);
	printf("Enter imaginary part of 2nd no.:");
	scanf("%lf", &complex2.imag);
	printf("1:Add 2:Sub 3:Mul\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case addition:
		 realsum = complex1.real + complex2.real;
		 imagsum = complex1.imag + complex2.imag;
		 printf("Resultant: %.2lf + i%.2lf", realsum, imagsum);
		 break;
	case subtraction:
		 realdiff = complex1.real - complex2.real;
		 imagdiff = complex1.imag - complex2.imag;
		 printf("Difference: %.2lf - i%.2lf", realsum, imagsum);
		 break;
	case multiplication:
		 realproduct = complex1.real * complex2.real;
		 imagproduct = complex1.imag * complex2.imag;
		 resproduct = realproduct - imagproduct;
		 printf("THE RESULTANT PRODUCT IS %.2lf", resproduct);
		 break;
	default:
		 break;
	}
	return 0;
}
