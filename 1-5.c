#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int replace (char*str, int size)
{
	int i,newsize,count=0;
	int j=0;
	char* strnew=NULL;

	for (i=0;i<size-1;i++)
	{
		if (str[i]==' ')
		{
			count+=1;
		}
	}
	printf("count=%d\n",count);
	newsize=size+(count*3)-count;
	printf("newsize=%d\n",newsize);
	strnew=(char*)malloc(newsize*sizeof(char));
	for (i=0;i<newsize-1;i++)
	{
		if (str[j]==' ')
		{
			strnew[i]='%';
			strnew[i+1]='2';
			strnew[i+2]='0';
			i+=2;
		}
		else
		{
			strnew[i]=str[j];
		}

		j+=1;
	}
	printf("%s",strnew);
	return 0;
}

int main (void)
{
	replace("size lj ",9);
	return 0;
}