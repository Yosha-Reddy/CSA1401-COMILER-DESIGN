#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
	int i,ic=0,cc=0,oc=0,j;
	char b[30],identifiers[30],constants[30],operators[30];
	printf("enter the string:");
	scanf("%[^\n]s",&b);
	for(i=0;i<strlen(b);i++)
	{
		if(isspace(b[i]))
		{
			continue;
		}
		else if(isalpha(b[i]))
		{
			identifiers[ic]=b[i];
			ic++;
		}
		else if(isdigit(b[i]))
		{
			constants[cc]=b[i];
			cc++;
		}
		else
		{
			if(b[i]=='*')
			{
				operators[oc]=b[i];
				oc++;
			}
			else if(b[i]=='+')
			{
				operators[oc]=b[i];
				oc++;
			}
			else if(b[i]=='=')
			{
				operators[oc]=b[i];
				oc++;
			}
			else if (b[i]=='-')
			{
				operators[oc]=b[i];
				oc++;
			}
		}
	}
	printf("identifiers:");
	for(j=0;j<ic;j++)
	{
		printf("%c",identifiers[j]);
	}
	printf("\n operators:");
	for(j=0;j<oc;j++)
	{
		printf("%c", operators[j]);
	}
	printf("\n constants:");
	for(j=0;j<oc;j++)
	{
		printf("%c", constants[j]);
	}
}
