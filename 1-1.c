#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int unique (char* str, int size)
 {
	int i,j;
	for (i=0; i<size; i++) {
		for (j=0;j<i;j++){
			if (str[i]==str[j])
				return 2;
		}
	}
	return 1;
}

int main (void) {
	int tf;
	char str[7]="aiujhi";
	tf=unique(&str,7);
	if (tf==1)
		printf("true\n");
	else
		printf("false\n");
	return 0;
}