#include<stdio.h>
int main()
{
	int ch;
	FILE *fptr = NULL;
	fopen_s(&fptr, "abc.txt", "r+");
	if (fptr != NULL)
	{
		while (!feof(fptr))
		{
			char ch = fgetc(fptr);
			if (ch != EOF)
			{
				printf("%c", ch);
			}
		}
		fclose(fptr);
	}
	else
	{
		printf("Error");
	}
	return 0;
}
