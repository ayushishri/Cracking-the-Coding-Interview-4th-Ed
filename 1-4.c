#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int swap (char* str, int j, int size2)
{
	char temp = str[j];
	str[j]=str[size2];
	str[size2]=temp;
	return 0;
}

bool anagram (char* str1, char* str2, int size1, int size2)
{printf("%s, %d, %s, %d", str1, size1, str2, size2);
	int i=0,j=0;
	if (size1!=size2)
		return false;
	if ((str1==NULL) || (str2==NULL))
		return false;
	size1-=2;
	size2-=2;
	for (i=0;i<=size1;i++)
	{
		for (j=0;j<=size2;j++)
		{
			if (str1[i]==str2[j])
			{
				swap(str2,j,size2);
				size2-=1;
				break;
			}
			else if ((j==size2) && (str1[i]!=str2[j]))
			{
				printf("false");
				return false;
			}
		}
	}
	printf("true");
	return true;
}

int main (void)
{printf("hi\n");

	bool tf=anagram("ayushi","ishuay",7,7);
	return 0;
}