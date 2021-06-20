 ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head -> next == NULL || k == 0) 
            return head;
        
        ListNode* curr = head;
        int len = 1;
        
        while(curr -> next != NULL)
        {
            len++;
            curr = curr -> next;
        }
        
        k %= len;
        curr -> next = head;
        
        while(--len >= k)
          curr = curr -> next;
        
        ListNode* first = curr -> next;
        curr -> next = NULL;
        
        return first; 
    }
