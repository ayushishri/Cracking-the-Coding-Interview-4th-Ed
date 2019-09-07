#include <stdio.h>
#include <stdbool.h>

int Paint(char**grid, char colour, int x, int y,int sizex, int sizey)
{
    if ((grid[x][y]==colour)||(x==sizex)||(y==sizey)||(x==0)||(y==0))
    {
        return -1;
    }
    
    if ((grid[x][y]!=colour))//there is a path iff there is an empty spot to the left or down
    {
        grid[x][y]=colour;
        Paint(grid, colour, x+1,y);
        Paint(grid, colour,x-1,y);
        Paint(grid, colour,x,y+1);
        Paint(grid, colour,x,y-1);
        return 0;
    }
    
    
}


