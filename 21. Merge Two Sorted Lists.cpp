ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(!l1 or !l2) return !l1 ? l2 : l1;
        
        
        ListNode *c1=l1,*c2=l2;
        ListNode *dummy=new ListNode(0);
        ListNode *temp=dummy;
        
        while(c1 and c2){
        if(c1->val<c2->val){
            temp->next=c1;
            temp=temp->next;
            c1=c1->next;
        }
        else{
            temp->next=c2;
            temp=temp->next;
            c2=c2->next;
        }
        if(c1) {
            temp->next = c1;
        }
        else if(c2) {
            temp->next = c2;
        }
        
        }
        return dummy->next;       
        
 }
