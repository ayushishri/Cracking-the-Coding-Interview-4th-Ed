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

void delete_at_pos (int pos)
{
     llnode *p=head;;
     llnode *temp1;
     llnode *temp2;
     int i;
     
     if (pos==1)
     {
     	head=p->next;
     	free(p);
     	return;
     }

    else
	{   
	 	for (i=1;i<pos-1;i++)
	    {
	      	p=p->next;
	    }
	    temp1=p;
	    temp2=p->next;
	    temp1->next=temp2->next;
	    free(temp2);
	    return;
    }
     
 }

int deleteduplicate()
{
	int i,j;
	llnode *p1;
	llnode *p2;
	if (head==NULL)
		return -1;
	p1=head;
	i=1;
	while((p1->next)!=NULL)
	{
		p2=p1;
		j=i;
		while ((p2->next)!=NULL)
		{
			p2=p2->next;
			j=j+1;
			if((p1->val)==(p2->val))
			{
				printf("i(p1)=%d, j(p2,pos)=%d, val=%d\n",i,j,p2->val);
				delete_at_pos(j);
			}
		}
		p1=p1->next;
		i=i+1;
	}
	return 0;
}


int main(void)
{
	llnode *list=NULL;
	insert_at_end(7);
	insert_at_end(5);
	insert_at_end(4);
	insert_at_end(5);
	ll_print();
    printf("\n");
    deleteduplicate();
    ll_print();

	return 0;
}