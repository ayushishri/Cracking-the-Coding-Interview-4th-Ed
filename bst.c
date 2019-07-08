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
//inorder, preorder, postorder are Depth First Traversals of a TREE (not the same as graph)
int inorder (bstNode (**root)) 
{
	if ((*root)==NULL)
		return -1;
	inorder (&((*root)->l));
	printf("%d\t",((*root)->val));
	inorder (&((*root)->r));

	return 0;
}

int preorder (bstNode (*root)) {
	if (root==NULL)
		return -1;
	printf("%d\n",(root->val));
	inorder (&(root->l));
	inorder (&(root->r));
	return 0;
}

int postorder (bstNode (*root)) {
	if (root==NULL)
		return -1;
	inorder (&(root->l));
	inorder (&(root->r));
	printf("%d\n",(root->val));
	return 0;
}



int max(int a, int b)
{
    return (a>=b)? a:b;
}

int height (bstNode *root)
{
    int lh, rh;
    if (root==NULL)
        return 0;
    return 1+max(height(root->l),height(root->r));
}

int isBalanced(bstNode(*root))
{
    int lh, rh;
    if (root==NULL)
        return -1;
    lh=height(root->l);
    rh=height(root->r);
    if ((abs(lh-rh)<=1)&&(isBalanced(root->l))&&(isBalanced(root->r)))//check at every node
        return 1;
    return 0;
    
}

int PrintGivenLevel(bstNode*root,int h)
{
    if (root==NULL)
        return -1;
    if (h==1)
        printf("%d\t",root->val);
    if (h>1)
    {
        PrintGivenLevel(root->l,h-1);
        PrintGivenLevel(root->r,h-1);
    }
}

int BreadthFirstTraversal (bstNode *root)
{
    int h=height(root);
    int i=0;
    for (i=1;i<=h;i++)
        PrintGivenLevel(root,i);
}

/*
int leftrotate(bstNode *root)
{
    if (root==NULL)
        return -1;
    bstNode *temp=root;
    root=root->r;
    root->l=temp;
    return 0;
}

int rightrotate(bstNode *root)
{
    if (root==NULL)
        return -1;
    bstNode *temp=root;
    root=root->l;
    root->r=temp;
    return 0;
}*/

int main (void) {
	int value=0;
	bstNode *bst=NULL;
	add_bst(&bst,3);
	add_bst(&bst,5);
	add_bst(&bst,1);
	add_bst(&bst,-1);
	add_bst(&bst,-5);
	add_bst(&bst,2);
	add_bst(&bst,4);
	add_bst(&bst,6);
	//inorder(&bst);
	BreadthFirstTraversal(bst);
	
}