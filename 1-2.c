#include <stdio.h>
#include <stdlib.h>

int reverse (char* str, int size)
{
	int i,j=0;
	char strnew[size];
	strnew[size-1]=str[size-1];
	for (i=size-2;i>=0;i--)
	{
		strnew[j]=str[i];
		j++;
	}
	printf("%s",strnew);
}

int main (void)
{
	int size=7;
	char str[]="ayushi";
	reverse (str, size);
	return 0;
}