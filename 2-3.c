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

int DeleteGivenNode(llnode **p1)
{
	if ((*p1)==NULL)
	{
	    printf("NULL\n");
	    return -1;
	}
//HANDLE EDGE CASE BELOW
//	else if (((*p1)->next)==NULL)
//	{
//	    free(p1);
//	    return 0;
//	}   
	llnode *p2=(*p1)->next;
	(*p1)->val=p2->val;
	(*p1)->next=p2->next;
	free(p2);
	return 0;
}


int main(void)
{
	insert_at_end(7);
	insert_at_end(5);
	insert_at_end(4);
	insert_at_end(6);
	ll_print();
    printf("\n");
    DeleteGivenNode(&(head->next));
    ll_print();
	return 0;
}