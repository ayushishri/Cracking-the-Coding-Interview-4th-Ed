#include <stdio.h>
#include <stdlib.h>


struct llnode{
    int val;
    struct llnode*next;
};

typedef struct llnode llnode;

int ll_print(llnode **head)
{
    llnode*p=(*head);
    if ((*head)==NULL)
    {
        printf("NULL");
        return -1;
    }
    else
    {
        while (p!=NULL)
        {
            printf("%d\t",p->val);
            p=p->next;
        }
    }
    printf("\n");
    return 0;
}

int insert_at_end(llnode **head, int val)
{
	llnode*p;
	llnode *tail=(llnode*)malloc(sizeof(llnode));
	
	if ((*head)==NULL)
	{
	    tail->val=val;
	    tail->next=NULL;
	    (*head)=tail;//DON'T do "p=tail;"
	}
	else
	{
	    p=(*head);
	    while ((p->next)!=NULL)
            p=p->next;
        p->next=tail;
        tail->val=val;
        tail->next=NULL;
	}
    
	return 0;
}

llnode *AddTwoLists(llnode **l1, llnode **l2)
{
    llnode*p1=(*l1);
    llnode*p2=(*l2);
    llnode*arr=NULL;
    int rval=0;
    int a,b,carry=0;
    
    if((*l1)==NULL)
        return p2;
    if((*l2)==NULL)
        return p1;
    
    while ((p1!=NULL)||(p2!=NULL))
    {
        if (p1!=NULL)
            a=p1->val;
        else
            a=0;

        if (p2!=NULL)
            b=p2->val;
        else
            b=0;
    
        rval=a+b+carry;
        if (rval>9)
        {
            carry=rval/10;
            rval=rval%10;
        }
        else
            carry=0;
        insert_at_end(&arr,rval);
        if (p1!=NULL)
            p1=p1->next;
        if (p2!=NULL)
            p2=p2->next;
    }
    ll_print(&arr);
    return arr;
}


int main(void)
{
	llnode *l1=NULL;
	llnode *l2=NULL;

	insert_at_end(&l1,3);
	insert_at_end(&l1,1);
	insert_at_end(&l1,5);
	ll_print(&l1);
	
	insert_at_end(&l2,8);
	
	ll_print(&l2);
	
	AddTwoLists(&l1,&l2);

	return 0;
}