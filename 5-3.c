#include <stdio.h>
#include <stdlib.h>

int GetBit (int n, int index)
{
    return n&(1<<index);
}

int SetBit(int n, int index, int value)
{
    int mask;
    if (value==1)
    {
        mask=(1<<index);
        n=n|mask;
    }
    else
    {
        mask=~(1<<index);
        n=n&mask;
    }
    return n;
}

int GetPrevious(int n)
{
    int i;
    int index=0;
    int zeros=0;
    while (GetBit(n,index)==1)
        index+=1;
    while (GetBit(n,index)==0)
    {
        index+=1;
        zeros+=1;
    }
    n=SetBit(n,index,0);
    
    index-=1;
    n=SetBit(n,index,1);
    zeros-=1;
    //make it ones
    for (i=index-1;i>=zeros;i--)
        SetBit(n,i,1);
    //make right most zeros
    for (i=zeros-1;i>=0;i--)
        SetBit(n,i,0);
    return n;
}

int GetNext(int n)
{
    int i;
    int index=0;
    int ones=0;
    while (GetBit(n,index)==0)
        index+=1;
    while (GetBit(n,index)==1)
    {
        index+=1;
        ones+=1;
    }
    n=SetBit(n,index,1);
    
    index-=1;
    n=SetBit(n,index,0);
    ones-=1;
    //make it zeros
    for (i=index-1;i>=ones;i--)
        SetBit(n,i,0);
    //make right most ones
    for (i=ones-1;i>=0;i--)
        SetBit(n,i,1);
    return n;
}


int main()
{
    printf("Hello World");

    return 0;
}
