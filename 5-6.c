#include <stdio.h>
#include <stdlib.h>

int swapOddEven(int N)
{
    int odd=N&0xaaaaaaaa;
    int even=N&55555555;
    odd=odd>>1;
    even=even<<1;
    N=odd|even;
    return N;
}

int main()
{
}
