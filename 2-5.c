int *CircularNode(llnode **head)
{
    llnode *p1=(*head);
    llnode *p2=(*head);
    
    while(p2->next!=NULL)
    {
        p1=p1->next;// slow pointer speed n
        p2=p2->next->next; // fast pointer speed 2n
        if (p1==p2) // circular LL -> they meet
            break;
    }
    
    if (p2==NULL) //check if faster pointer reached NULL
        return -1;
    
    p1=(*head);
    while (p1!=p2)
    {
        p1=p1->next;
        p2=p2->next;
    }
    return p2;
}
