#include <stdio.h>

int printParenthesis(int n)
{
    helper(n,0,0,0);
}

int helper (int n, int open, int close, int pos)
{
    static char str[100];
    if (close==n)
    {
        printf("%s\n",str);
        return 0;
    }
    else
    {
        if(open>close)
        {
            str[pos]=')';
            helper(n,open,close+1,pos+1);
        }
        
        if (open<n)
        {
            str[pos]='(';
            helper(n,open+1,close,pos+1);
        }
    }
}

int main()
{
    printParenthesis(3);

    return 0;
}
