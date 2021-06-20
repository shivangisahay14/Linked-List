struct node*update(struct node*start,int p)
{
    if(!start or !start->next or p==0){
        return start;
    }
     struct node* curr = start;
     
     int count = 1;
    while (count < p && curr != NULL) {
        curr = curr->next;
        count++;
    }
    
    struct node *Nthnode=curr,*head;
    
    while(curr->next != NULL){
        curr=curr->next;
    }
    
    
    curr->next=start;
    start->prev=curr;
    
    head=Nthnode->next;
    head->prev=NULL;
    Nthnode->next=NULL;
    
    return head;
    
}
