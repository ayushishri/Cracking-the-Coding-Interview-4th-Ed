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
	printf("pushed %d\n", val);
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

stack* sort(stack *s)
{
    int val=0;
    int store=0;
    stack *s2=createStack(s->size);
    while (isEmpty(s)==0)
    {
        if ((isEmpty(s2)==1)||((s2->arr[s2->top])<=(s->arr[s->top])))
        {
            val=pop(s);
            push(s2,val);
        }
        else if ((s2->arr[s2->top])>(s->arr[s->top]))
        {
            store=pop(s);//smaller value stored
            while((s2->arr[s2->top])>store)
            {
                val=pop(s2);
                push(s,val);
            }
            push(s2,store);
        }
    }
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
	stack *s=createStack(4);
	push(s,4);
	push(s,2);
	push(s,3);
	push(s,7);
	s=sort(s);
	printstack(s);
	return 0;
}