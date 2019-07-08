//implementing stack using an array

#include <stdio.h>
#include <stdlib.h>

struct stack{
	int top;
	int size;
	int *arr;//store stack array here
};

typedef struct stack stack;

stack* createStack(int size)
{
	stack *s=(stack*)malloc(sizeof(stack));
	s->size=size;
	s->top=-1;//starting position of pointer
	s->arr=(int*)malloc(size*sizeof(int)); //store stack content in this arr
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
	if (isFull(s)==1)
		return -1;
	s->top=(s->top)+1;
	s->arr[s->top]=val;
	return 0;
}


int enQ(stack *s, int val)
{
    push(s,val);
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

stack* deQ(stack *s)
{
    stack *s2=createStack(s->size);
    int i=0;
    int val=0;
    for(i=0;i<(s->size);i++)
    {
        val=pop(s);
        push(s2,val);
    }
    val=pop(s2);
    printf("%d\t",val);
    return s2;
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
	stack *Q=createStack(4);
	enQ(Q,4);
	enQ(Q,2);
	enQ(Q,3);
	enQ(Q,7);
	Q=deQ(Q);
//	printstack(Q);
	return 0;
}