case1: if you have to return product as a linked list

Node* reverseList(Node* head) {
         if (head == NULL) 
            return NULL; 
        if (head->next == NULL) 
            return head; 
        
        Node *q=NULL;
        Node *r=NULL;
        Node *p=head;
        
        while(p!=NULL){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        head=q;
        
        return q;
        
    }
Node* multiplyLLWithDigit(Node *head,int digit){
    
    Node *dummy=new Node(-1);
    Node *ac=dummy;
    Node *curr=head;
    int carry=0;
    while(curr!=NULL or carry!=0){
        int sum=carry + (curr!=NULL ? curr->data : 0)*digit;
        carry=sum/10;
        
        ac->next=new Node(sum%10);
        ac=ac->next;
        
        if(curr) curr=curr->next;
    }
    return dummy->next;
    
}
void addTwoNumbers(Node* head, Node* ans_itr) {
        
        Node *dummy=new Node(-1);
        Node *temp=dummy,*c1=head,*c2=ans_itr;
        
        int carry=0;
        while(c1 or carry){
            int sum=carry+(c1!=NULL ? c1->data : 0)+(c2->next!=NULL ? c2->next->data : 0);
            int digit =sum%10;
            carry=sum/10;
            
            if(c2->next) c2->next->data=digit;
            else c2->next=new Node(digit);
            
            if(c1) c1=c1->next;
            c2=c2->next;
            
        }
            
        
    }
/*You are required to complete this method*/
Node*  multiplyTwoLists (Node* l1, Node* l2)
{
    l1=reverseList(l1);
    l2=reverseList(l2);
    
    Node *l2_itr=l2;
    Node *dummy=new Node(-1);
    Node *ans_itr=dummy;
    while(l2){
        Node *prod= multiplyLLWithDigit(l1,l2_itr->data);
        l2_itr=l2_itr->next;
        
        addTwoNumbers(prod,ans_itr);
        ans_itr=ans_itr->next;
    }
    return reverseList(dummy->next);
    
  //Your code here
}

Case 2 : if you have to return prod as integer
long long  multiplyTwoLists (Node* l1, Node* l2)
{
    
   long long N= 1000000007;
    long long num1 = 0, num2 = 0;
    while (l1 || l2){
         
        if(l1){
            num1 = ((num1)*10)%N + l1->data;
            l1 = l1->next;
        }
         
        if(l2)
        {
            num2 = ((num2)*10)%N + l2->data;
            l2 = l2->next;
        }
         
    }
    return ((num1%N)*(num2%N))%N;
}
