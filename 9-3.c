#include <stdio.h>
#include "sort.h"

int findinrotatedarray(int *arr, int l, int r, int key)
{
    int m=(l+r)/2;
    int pIndex=findPartition(arr,l,r);
    if (arr[pIndex]<=key<=arr[r])
    {
        m=(pIndex+r)/2;
        while (arr[m]!=key)
        {
            
        }
    }
    else
    {
        //search left
        
    }
}

int findPartition(int arr, int l, int r)
{
    int m=(l+r)/2;
    if (m==0) //edge case
        if (arr[m]<arr[r])
            return m
    else if (arr[m-1]>arr[m])
        return m;
    else
    {
        findPartition(arr,l,m);
        findPartition(arr,m+1,r);
    }
}