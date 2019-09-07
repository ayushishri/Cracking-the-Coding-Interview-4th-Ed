#include <stdio.h>

int swap(char*str,int a, int b)
{
    char temp=str[a];
    str[a]=str[b];
    str[b]=temp;
    return 0;
}

int permute (char*str, int l, int r)
{
    int i;
    if (l==r)
    {
        printf("%s\n",str);
    }
    else
    {
        for (i=l;i<=r;i++)
        {
            swap(str,l,i);
            permute(str,l+1,r);
            swap(str,l,i);
        }
    }
}

int main()
{
    char str[]="abc";
    permute(str,0,2);

    return 0;
}
