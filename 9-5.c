#include<stdio.h>
#include<string.h>

int compareStr(char*A, char*B)
{
    int i=0;
    while (A[i]=B[i] && A[i]!='\0')
        i++;
    if (A[i] > B[i]) 
        return -1; 
  
    return (A[i] < B[i]); 
}

int findString(char*arr[], int l, int r, char*key)
{
    //modified binary search
    int i,m,left,right;
    if (l>r)
        return -1;
    mid=(l+r)/2;
    if (arr[mid]='')
    {
        left=mid-1;
        right=mid+1;
        while (1)
        {
            if (left<l && right>r)
                return -1;
            if (right<=left && arr[right]!='')
            {
                mid=right;
                break;
            }
            if (left>=right && arr[left]!='')
            {
                mid=left;
                break;
            }
            right++;
            left--;
            
            if (compareStr(arr[mid],key)==0)
                return mid;
            if (compareStr(arr[mid],key)<0)
                findString(arr,mid+1,r,key);
            else
                findString(arr,l,mid-1,key);
        }
    }
}