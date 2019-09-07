#include <stdio.h>

int NthFibonacci(int n)
{
    int i,prev1=1,prev2=0,curr;
    if (n==0)
        return 0;
    if (n==1)
        return 1;
    for (i=2;i<=n;i++)
    {
        curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return curr;
}

int main()
{
    printf("%d",NthFibonacci(6));

    return 0;
}
