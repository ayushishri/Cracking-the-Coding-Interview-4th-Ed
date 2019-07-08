#include<stdio.h>
#include<stdlib.h>

struct node {
    int dest;//dest=destination
    struct node *next;
};

struct edge {
    struct node *head;//edge is an array of nodes (adjacency list)
};

struct graph {
    int size; //size of graph is the number of vertices
	struct edge *arr;
};

typedef struct node node;
typedef struct edge edge;
typedef struct graph graph;

node* createNode (int dest)
{
    node *new=(node*)malloc(sizeof(node));
    new->dest=dest;
    new->next=NULL;
    return new;
}

graph* createGraph (int size)
{
    graph *new=(graph*)malloc(sizeof(graph));
    new->size=size;
    new->arr=(edge*)malloc(size*sizeof(edge));
    return new;
}

//Add edge from source to destination
int createEdge (graph *G, int src, int dest)
{
    node *new=createNode(dest);
    new->next=G->arr[src].head;
    G->arr[src].head=new;
    //UNDIRECTED:
    /*
    new=createNode(src);
    new->next=G->arr[dest].head;
    G->arr[dest].head=new;*/
    
    return 0;
}

int printGraph(graph *G) 
{
    int i;
    node *new;
    for (i=1;i<=(G->size);i++)//graph starts with one (1) and ends with (size)
    {
        new=G->arr[i].head;
        printf("Adjacency list of vertex %d\n",i);
        while (new)
        {
            printf(" -> %d",new->dest);
            new=new->next;
        }
        printf("\n");
    }
}

int main (void)
{
    graph *G=createGraph(5);//graph with 5 vertices
    
    createEdge(G,1,2);
    createEdge(G,1,5);
    createEdge(G,5,2);
    createEdge(G,5,3);
    createEdge(G,3,2);
    createEdge(G,3,4);
    printGraph(G);
    return 0;
}





