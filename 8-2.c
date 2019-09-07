#include <stdio.h>
#include <stdbool.h>

int HowManyPaths(int x, int y)
{
    if ((x==1)||(y==1))//there is a path iff there is an empty spot to the left or down
        return 1;
    return HowManyPaths(x-1,y)+HowManyPaths(x,y-1);
    
}


int main()
{
    printf("%d",HowManyPaths(3,3));
    return 0;
}
