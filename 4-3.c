#include<stdio.h>
#include<stdlib.h>

struct bstNode {
	int val;
	struct bstNode *l; /*left pointer*/
	struct bstNode *r; /*right pointer*/
};

typedef struct bstNode bstNode;

int add_bst(bstNode **root, int val) 
{
	if (root==NULL)
		return -1;
	if (*root==NULL) 
	{
		(*root)=(bstNode*)malloc(sizeof(bstNode));
		(*root)->val=val;
		(*root)->l=NULL;
		(*root)->r=NULL;
	}
	else 
	{
		if (((*root)->val)<val)
			add_bst(&((*root)->r),val);
		else
			add_bst(&((*root)->l),val);
	}
	return 0;
}

bstNode* find_bst (bstNode**root, int value)
{
    bstNode *p=NULL;
    if (*root==NULL)
        return p;
    if ((*root)->val==value)
    {
        p=(*root);
        return p;
    }
    if (value<(*root)->val)
        find_bst(&((*root)->l),value);
    else
        find_bst(&((*root)->r),value);
}

int delete_bst(bstNode**root, int value)
{
    bstNode *p;
    bstNode *p2;
    bstNode *temp;
    if ((*root)==NULL)//if tree is NULL (does not exist)
        return -1;
    p=find_bst(&(*root),value);
    if (p==NULL)// if key was not found in tree
        return -1;
    else if ((p->l==NULL)&&(p->r==NULL))//CASE 1: No child
    {
        free(p);
    }
    else if (p->l==NULL)//CASE 2: 1 child
    {
        temp=p->r;
        p->val=temp->val;//switch value with child
        free(temp);//free the empty node
    }
    else if (p->r==NULL)//CASE 2: 1 child
    {
        temp=p->l;
        p->val=temp->val;//switch value with child
        free(temp);//free the empty node
    }
    else //CASE 3: 2 children
    {
        p2=p->r;//Go one right and then as left as possible to find the value to switch this node with
        while ((p2->l)!=NULL)
        {
            p2=p2->l;
        }
        p->val=p2->val;//switching key-val with next big value
        temp=p2;//free this leaf node
        free(temp);
    }
    return 0;
}



bstNode* helper (bstNode*head,int *arr, int start, int end)
{
    if (start<end)
        return NULL;
    int mid=(start+end)/2;
    add_bst(&head,arr[mid]);
    helper(head->l,arr,start,mid-1);
    helper(head->r,arr,mid+1,end);
    return head;
}

bstNode* ArrayToBST(int*arr,int size)
{
    bstNode *head=NULL;
    head=helper(head,arr,0,size-1);
    return head;
}

int main (void) {
	int arr[9]={0,1,2,3,4,5,6,7,8};
	bstNode *head=ArrayToBST(arr,9);
	
}