#include <stdio.h>
#include <stdlib.h>

int rotate (int N, int image[N][N])
{
	int arr[N][N];
	int i,j;
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
			arr[N-j-1][i]=image[i][j];
		}
	}
	//printing
	for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
				printf("%d, ",arr[i][j]);
			printf("\n");
		}
		return 0;
}

int main (void)
{
	
	int image[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	rotate(3,image);
	return 0;
}