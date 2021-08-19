ListNode* rotateRight(ListNode* head, int k) {
        // edge cases 
        if (!head || !head->next || k == 0) return head;
        
        // compute the length
        ListNode *cur = head;
        int len = 1;
        while (cur->next && ++len) 
            cur = cur->next;
        
        // go till that node
        cur->next = head;
        k = k % len; 
        k = len - k;
        while (k--) cur = cur->next;
        
        // make the node head and break connection 
        head = cur->next;
        cur->next = NULL;
        
        
        return head; 
    }





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
