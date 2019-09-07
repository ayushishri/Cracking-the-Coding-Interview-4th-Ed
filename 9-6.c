#include<stdio.h>

int matrixsearch(int*mat[], int M, int N, int key)
{
    int row=0;
    int col=N-1;
    while(row<M && col>=0)
    {
        if (mat[row][col]==key)
            return 1;
        else if (mat[row][col]>key)
            col--;
        else
            row++;
    }
    return 0;
}