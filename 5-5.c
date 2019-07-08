#include <stdio.h>
#include <stdlib.h>

int BitsToConvert(int A, int B)
{
    int ones=0;
    int mask=A^B;
    while (mask)
    {
        ones=ones+(mask&1);
        mask=mask>>1;
    }
    return ones;
}

int main()
{
    printf("%d",BitsToConvert(31,14));
}
