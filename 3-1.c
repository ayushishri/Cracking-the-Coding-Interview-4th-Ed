//implementing stack using an array

#include <stdio.h>
#include <stdlib.h>

struct stack{
	int top1;//start of first stack
	int top2;//start of second stack
	int top3;//start of third stack
	int size;//total size
	int *arr;//store stack array here
};

typedef struct stack stack;

stack* createStack(int size)
{
	stack *s=(stack*)malloc(sizeof(stack));
	s->size=size;
	s->top1=-1;//starting position of pointer
	s->top2=-1;
	s->top3=-1;
	s->arr=(int*)malloc((s->size)*sizeof(int)); //store stack content in this arr
	printf("stack created.\n");
	return s;
}

int isFull (stack *s)
{
	if (((s->top1)+(s->top2)+(s->top3))==((s->size)-1))
		return 1;
	else 
		return 0;
}

int isEmpty (stack *s)
{
	if (((s->top1)+(s->top2)+(s->top3))==-3)
		return 1;
	else 
		return 0;
}

int push(stack *s, int val, int whichstack)//add at the end of stack
{
	if (isFull(s)==1)
		return -1;
	if (whichstack==1)
	{
    	s->top1+=1;
    	s->top2+=1;
    	s->top3+=1;
    	s->arr[s->top1]=val;
	}
	else if (whichstack==2)
	{
    	s->top2+=1;
    	s->top3+=1;
    	s->arr[s->top2]=val;
	}
	else if (whichstack==3)
	{
    	s->top3+=1;
    	s->arr[s->top3]=val;
	}
	printf("pushed %d\n", val);
	return 0;
}

int pop(stack *s, int whichstack)//remove from end of arr
{
	int rval;
	if (isEmpty(s)==1)
		return -1;
	if (whichstack==1)
	{
	    rval=s->arr[s->top1];
	    s->top1-=-1;
	    s->top2-=-1;
	    s->top3-=-1;
	}
	else if (whichstack==2)
	{
	    rval=s->arr[s->top2];
	    s->top2-=-1;
	    s->top3-=-1;
	}
	if (whichstack==3)
	{
	    rval=s->arr[s->top3];
	    s->top3-=-1;
	}
	printf("popped %d\n", rval);
	return rval;
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