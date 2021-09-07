ListNode* swapPairs(ListNode* head) {
        
        if(!head or !head->next) return head;
        
        ListNode* p = head;
        ListNode* res = head->next;
        ListNode* q; ListNode* temp;
        
        while(true)
        {
            q = p->next;
            temp = q->next;
            q->next = p;
            
            if(temp == NULL || temp->next == NULL) {
                p->next = temp;
                break;
            }
            p->next = temp->next;
            p = temp;
        }
        return res;            
               
    }
