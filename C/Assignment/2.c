#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[1000];
	scanf("%[^\n]%*c",a);
	int i,let=0,spa=0,tab=0,dig=0,sym=0;
	for(i=0;i<strlen(a);i++)
	{
		if((a[i]>='a' && a[i]<='z') ||(a[i]>='A' && a[i]<='Z')) let++;
		else if(a[i]>='0' && a[i]<='9') dig++;
		else if(a[i]=='\\')
		{
			if(i+1<strlen(a) && a[i+1]=='t')
			{
				i++;tab++;
			}
		}
		else if(a[i]=='!' || a[i]=='~' || a[i]=='`' || a[i]=='@' || a[i]=='#' || a[i]=='$' || a[i]=='%' || a[i]=='^' || a[i]=='&' || a[i]=='*' || a[i]=='(' || a[i]==')' || a[i]=='-' || a[i]=='_' || a[i]=='+' || a[i]=='=' || a[i]=='<' || a[i]==',' || a[i]=='>' || a[i]=='.' || a[i]=='/' || a[i]=='?' || a[i]=='"' || a[i]==';')
		sym++;
		else if(a[i]==' ') spa++;
	}
	printf("Letters:%d, Symbols:%d, Digits:%d, spaces:%d, tabs:%d\n",let,sym,dig,spa,tab);
	return 0;
}

