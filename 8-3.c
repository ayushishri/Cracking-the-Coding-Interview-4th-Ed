#include <stdio.h>
#include <math.h>

int SubsetsOfSets(int *arr, int size)
{
    int i,j;
    unsigned int mask;
    mask=pow(2,size);//2^size
    for (i=0;i<mask;i++)
    {
        for (j=0;j<size;j++)
        {
            if (i&(1<<j))//check if the jth bit is a part of the given arr
                printf("%d",arr[j]);
        }
        printf("\n");
    }
}

int main()
{
    int arr[]={0,1,2,3};
    SubsetsOfSets(&arr,4);

    return 0;
}
