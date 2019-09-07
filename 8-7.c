#include <stdio.h>

int helper (float total, int i, float *arr)
{
    int numcoin;
    if (i>=4)
        return 0;
    numcoin=total/arr[i];
    printf("%d coins of %f\n", numcoin,arr[i]);
    total=total-numcoin*arr[i];
    helper(total,i+1,arr);
    return 0;
}
int represent(float n)
{
    float arr[]={0.25,0.10,0.05,0.01};
    helper(n,0,arr);
    return 0;
}

int main()
{
    represent(5.8);
}
