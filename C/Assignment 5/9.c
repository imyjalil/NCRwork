#include<stdio.h>
int main()
{
	char ch='\0';
	FILE *fptr = NULL;
	fopen(&fptr, "capital_small_conversions.txt", "w");
	if (fptr != NULL)
	{
		while (ch != '\n')
		{
			scanf("%c", &ch);
			if (ch >= 'a' && ch <= 'z')
			{
				fputc(ch - 32, fptr);
			}
			else if (ch >= 'A' && ch <= 'Z')
			{
				fputc(ch + 32, fptr);
			}
			else if (ch != EOF)
			{
				fputc(ch, fptr);
			}
		}
	}
	else
	{
		printf("Error");
	}
	return 0;
}
