#include <stdio.h>
#include <stdlib.h>


struct llnode{
    int val;
    struct llnode*next;
};

typedef struct llnode llnode;
llnode *head;

int ll_print()
{
    llnode*p=head;
    if (head==NULL)
        return -1;
    else
    {
        while (p!=NULL)
        {
            printf("%d\t",p->val);
            p=p->next;
        }
    }
    return 0;
}

int insert_at_end(int val)
{
	llnode*p;
	llnode *tail=(llnode*)malloc(sizeof(llnode));
	
	if (head==NULL)
	{
	    tail->val=val;
	    tail->next=NULL;
	    head=tail;//DON'T do "p=tail;"
	}
	else
	{
	    p=head;
	    while ((p->next)!=NULL)
            p=p->next;
        p->next=tail;
        tail->val=val;
        tail->next=NULL;
	}
    
	return 0;
}


int FindNthToLast(int n)
{
	int x=1;
	int i=1;
	llnode *p1=head;
	llnode *p2=p1;
	if (head==NULL)
	    return -1;
	while ((p1->next)!=NULL)
	{
		p1=p1->next;
		x+=1; //determine size of linked list
	}
	for(i=1;i<=(x-n);i++)
	{
		p2=p2->next;
	}
	printf("%d\n",p2->val);
	return 0;
}


int main(void)
{
	llnode *list=NULL;
	insert_at_end(7);
	insert_at_end(5);
	insert_at_end(4);
	insert_at_end(6);
	ll_print();
    printf("\n");
    FindNthToLast(1);
	return 0;
}