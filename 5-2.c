#include <stdio.h>
#include <stdlib.h>



int decimalToBinary (char*s)
{
    int r, q,i,count=0;
    double R;
    double num=atof(s);
    int x=num/1;
    num=num-(double)x;
    while (x>0)
    {
        q=x/2;
        r=x%2;
        printf("%d",r);//manipulate this so its flipped
        x=q;
    }
    printf(".");
    //for the decimal part.
    while ((num!=0.0)&&count<=30)
    {
        num=num*2;
        if (num>=1.0)
        {
            printf("1");
            num=abs(num-1.0);
        }
        else
            printf("0");
        count+=1;
    }
}
int main (void)
{
    decimalToBinary("19.4");
    return 0;
}