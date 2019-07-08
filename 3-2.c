//2D stack
//FOR O(1) TIME COMPLEX, KEEP TRACK OF MINIMUM FOR EACH VAL PUSHED 
//implementing stack using an array

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack{
	int top;
	int size;
	int *arr[2];//store stack in an array with 2 rows
};

typedef struct stack stack;
bool minvalassigned=false;
stack* createStack(int size)
{
	stack *s=(stack*)malloc(sizeof(stack));
	s->size=size;
	s->top=-1;//starting position of pointer
	s->arr[0]=(int*)malloc(size*sizeof(int));//malloc columns of 1st row
	s->arr[1]=(int*)malloc(size*sizeof(int));//malloc columns of 2nd row
	printf("stack created.\n");
	return s;
}

int isFull (stack *s)
{
	if ((s->top)==((s->size)-1))
		return 1;
	else 
		return 0;
}

int isEmpty (stack *s)
{
	if ((s->top)==-1)
		return 1;
	else 
		return 0;
}

int push(stack *s, int val)//add at the end of arr
{
	int minval;
	if (isFull(s)==1)
		return -1;
	if(minvalassigned==false)
	{
	    minval=val;
	    minvalassigned=true;
	}
	else if (val<(s->arr[1][s->top]))//check if the current val is less that previous minimum
	    minval=val;//if yes, change minval to current val
	s->top=(s->top)+1;
	s->arr[0][s->top]=val;//push val
	s->arr[1][s->top]=minval;//assign current minimum
	printf("pushed %d\n", val);
	return 0;
}

int pop(stack *s)//remove from end of arr
{
	int rval;
	if (isEmpty(s)==1)
		return -1;
	rval=s->arr[0][s->top];
	s->top=(s->top)-1;
	printf("popped %d\n", rval);
	return rval;
}

int min(stack *s)
{
    int minval=s->arr[1][s->top];
    printf("minval=%d",minval);
    return minval;
}

int printstack(stack *s)
{
    int i,j;
    for (i=0;i<2;i++)
    {
        for (j=0;j<=(s->top);j++)
            printf("%d\t",s->arr[i][j]);
        printf("\n");
    }
}

int main (void)
{
	int a;
	stack *s=createStack(4);
	push(s,4);
	push(s,-3);
	push(s,3);
	push(s,1);
    min(s);
	printf("\n");
	printstack(s);
	
	
	
	return 0;
}