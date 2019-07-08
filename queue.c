//implementing queue using an array

#include <stdio.h>
#include <stdlib.h>

struct queue{
	int top;
	int size;
	int *arr;//store queue array here
};

typedef struct queue queue;

queue* createQueue(int size)
{
	queue *s=(queue*)malloc(sizeof(queue));
	s->size=size;
	s->top=-1;//starting position of pointer
	s->arr=(int*)malloc(size*sizeof(int)); //store queue content in this arr
	printf("queue created.\n");
	return s;
}

int isFull (queue *s)
{
	if ((s->top)==((s->size)-1))
		return 1;
	else 
		return 0;
}

int isEmpty (queue *s)
{
	if ((s->top)==-1)
		return 1;
	else 
		return 0;
}

int enQ(queue *s, int val)//add at the end of arr
{
	if (isFull(s)==1)
		return -1;
	s->top=(s->top)+1;
	s->arr[s->top]=val;
	printf("pushed %d\n", val);
	return 0;
}

int deQ(queue *s)//remove from end of arr
{
	int rval,i;
	if (isEmpty(s)==1)
		return -1;
	rval=s->arr[0];
	for (i=0;i<(s->top);i++)
	{
		s->arr[i]=s->arr[i+1];
	}
	s->top=(s->top)-1;
	printf("popped %d\n", rval);
	return rval;
}
/*
int main (void)
{
	int a;
	queue *s=createQueue(4);
	enQ(s,4);
	enQ(s,2);
	enQ(s,3);
	enQ(s,7);
	a=deQ(s);
	a=deQ(s);
	a=deQ(s);
	return 0;
}*/