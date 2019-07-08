#include <stdio.h>
#include <stdlib.h>

int makeBitSubString (int N, int M, int i, int j)
{
    int max=~0;
    int left=(max-((1<<j)-1));
    int right=(max-((1<<i)-1));
    int ans=left^right;
    ans=~ans;
    N=N&ans;
    N=N|(M<<i);
    printf("%b",N);
    return N;
    
}
int main (void)
{
    makeBitSubString(10000000000,10101,2,6);
    return 0;
}