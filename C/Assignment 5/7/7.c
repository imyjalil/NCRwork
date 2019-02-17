#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void ones_complement(char*);
int btoi(char*);

int main(int argc,char *argv[])
{
	FILE *fptr = NULL,*fptr2=NULL;
	fopen_s(&fptr, argv[1], "r");
	fopen_s(&fptr2,"write.txt","w");
	if (fptr != NULL && fptr2!=NULL)
	{
		while (!feof(fptr))
		{
			char ch = fgetc(fptr);
			if (ch != EOF)
			{
				int n = ch;
				char binary[33];
				_itoa_s(n, binary, 33, 2);
				ones_complement(binary);
				fputc(ch, fptr2);
				fputs(binary, fptr2);
			}
		}
		fclose(fptr);
		fclose(fptr2);
	}
	return 0;
}

int btoi(char binary[])
{
	int binary_length = strlen(binary);
	int decimal = 0, count = 0;
	for (int bit = binary_length - 1; bit >= 0; bit--)
	{
		decimal += ((binary[bit] - 48) *(int)pow(2, count));
		count++;
	}
	return decimal;
}

void ones_complement(char *binary)
{
	for (int i = 0; binary[i]; i++)
	{
		if (binary[i] == '0')
			binary[i] = '1';
		else
			binary[i] = '0';
	}
}
