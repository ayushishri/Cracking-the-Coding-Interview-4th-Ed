//implementing stack using an array

#include <stdio.h>
#include <stdlib.h>

struct stack{
	int top;
	int size;
	int *arr;//store stack array here
};

typedef struct stack stack;

stack *s1;
stack *s2;
stack *s3;

stack* createStack(int size)
{
	stack *s=(stack*)malloc(sizeof(stack));
	s->size=size;
	s->top=-1;//starting position of pointer
	s->arr=(int*)malloc(size*sizeof(int)); //store stack content in this arr
	//printf("stack created.\n");
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
	if (isFull(s)==1)
		return -1;
	s->top=(s->top)+1;
	s->arr[s->top]=val;
	return 0;
}

int pop(stack *s)//remove from end of arr
{
	int rval;
	if (isEmpty(s)==1)
		return -1;
	rval=s->arr[s->top];
	s->top=(s->top)-1;
	return rval;
}

void hanoi(int n,stack *from, stack *aux, stack *to)
{
    int val=0;
    if (n==1)
    {
        val=pop(from);
        push(to,val);
        return;
    }
    if (n>-1)
    {
        hanoi(n-1,from,aux,to);
        val=pop(from);
        push(to,val);
        hanoi(n-1,aux,to,from);
    }
}

void printstack(stack*s)
{
    int i=0;
    for(i=0;i<=s->top;i++)
        printf("%d\t",s->arr[i]);
    printf("\n");
    return;
}

int main (void)
{
	int a;
	s1=createStack(3);
	s2=createStack(3);
	s3=createStack(3);
	push(s1,3);
	push(s1,2);
	push(s1,1);
	stack*p1=s1;
	stack*p2=s2;
	stack*p3=s3;
	hanoi(3,p1,p2,p3);
	printf("\nstack3:\n");
	printstack(s1);
	printstack(s2);
    printstack(s3);
    return 0;
}