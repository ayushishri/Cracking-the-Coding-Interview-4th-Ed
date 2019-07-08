//implementing stack using an array

#include <stdio.h>
#include <stdlib.h>

struct stack{
	int top;
	int size;
	int *arr;//store stack array here
};

struct SetOfStacks{
    int topstack;
	int sizestack;
	stack *nextstack;//store array of stacks here
};

typedef struct stack stack;

typedef struct SetOfStacks SetOfStacks;


stack* createStack(int size)
{
	stack *s=(stack*)malloc(sizeof(stack));
	s->size=size;
	s->top=-1;//starting position of pointer
	s->arr=(int*)malloc(size*sizeof(int)); //store stack content in this arr
	printf("stack created.\n");
	return s;
}

SetOfStacks* createset(int size)
{
    SetOfStacks *set=(SetOfStacks*)malloc(sizeof(SetOfStacks));
	set->sizestack=size;
	set->topstack=-1;//starting position of pointer
	set->nextstack=(stack*)malloc(size*sizeof(stack)); //store stack content in this arr
	printf("stack set created.\n");
	return set;
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

int isFullSet ()
{
	if ((set->topstack)==((set->sizestack)-1))
		return 1;
	else 
		return 0;
}

int isEmptySet ()
{
	if ((set->topstack)==-1)
		return 1;
	else 
		return 0;
}

int push(stack *s, int val)//add at the end of arr
{
	if (isFull(s)==1)
	{
		return -1;
	}
	s->top=(s->top)+1;
	s->arr[s->top]=val;
	printf("pushed %d\n", val);
	return 0;
}

int pushSet(stack *s)//add at the end of arr
{
	if (isFullSet==1)
	{
		return -1;
	}
	set->topstack=(set->topstack)+1;
	set->nextstack[set->topstack]=s;
	printf("pushed set\n");
	return 0;
}

int pop(stack *s)//remove from end of arr
{
	int rval;
	if (isEmpty(s)==1)
		return -1;
	rval=s->arr[s->top];
	s->top=(s->top)-1;
	printf("popped %d\n", rval);
	return rval;
}

int popSet()//remove from end of arr
{
	if (isEmptySet==1)
		return -1;
	set->topstack=(set->topstack)-1;
	printf("popped");
	return 0;
}

int main (void)
{
	int a;
	stack *s=createStack(4);
	push(s,4);
	push(s,2);
	push(s,3);
	push(s,7);
	a=pop(s);
	return 0;
}