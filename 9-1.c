//METHOD 2 IS MORE EFFICIENT
#include <stdio.h>
#include "sort.h"

int mergetwoarrMETHOD1(int *A, int *B, int sizeA, int sizeB)
{
    int i,j,k;
    int sizeC=sizeA-sizeB;
    int C[sizeC];
    for (i=0;i<sizeC;i++)
        C[i]=A[i];
    i=0;
    j=0;
    k=0;
    while (i<sizeC && j<sizeB)
    {
        if (C[i]<=B[j])
        {
            A[k]=C[i];
            i++;
            k++;
        }
        else
        {
            A[k]=B[j];
            j++;
            k++;
        }
    }
    while (i<sizeC)
    {
        A[k]=C[i];
        i++;
        k++;
    }
    while (j<sizeB)
    {
        A[k]=B[j];
        j++;
        k++;
    }
}
int mergetwoarrMETHOD2(int *A, int *B, int sizeA, int sizeB)
{
    int i,j,k;
    
    i=sizeA-sizeB-1;
    j=sizeB-1;
    k=sizeA-1;
    while (i>=0 && j>=0)
    {
        if (A[i]>=B[j])
        {
            A[k]=A[i];
            i--;
            k--;
        }
        else
        {
            A[k]=B[j];
            j--;
            k--;
        }
    }
    while (i>=0)
    {
        A[k]=A[i];
        i--;
        k--;
    }
    while (j>=0)
    {
        A[k]=B[j];
        j--;
        k--;
    }
}

int main ()
{
    int A[8]={1,4,7,8};
    int B[4]={2,5,6,10};
    mergetwoarrMETHOD1(A,B,8,4);
    printarr(A,8);
}