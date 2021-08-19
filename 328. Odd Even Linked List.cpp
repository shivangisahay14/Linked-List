Node* divide(int N, Node *head){
        if(!head or !head->next) return head;
        
        Node *dummyeven=new Node(-1);
        Node *dummyodd=new Node(-1);
        Node *etail=dummyeven,*otail=dummyodd,*curr=head;
        while(curr){
            if((curr->data%2) !=0){
                otail->next=curr;
                otail=otail->next;
            }
            
            else{
                etail->next=curr;
                etail=etail->next;
                
            }
            curr=curr->next;
        }
        
        
        etail->next=dummyodd->next;
        otail->next=NULL;
        
        
        return dummyeven->next;
        
    }




class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        //Boundary cases
        if(!head)
            return head;
        
        ListNode *end = head;
        int counter = 0;
        while(end->next)
        {    end = end->next;   counter +=1;    }
        
        counter = counter&1?(counter/2)+1:counter/2;
        ListNode *temp = head;
        while(counter--)
        {
            end->next = temp->next;
            temp->next = temp->next->next;
            end->next->next = NULL;
            temp = temp->next;
            end = end->next;
        }
        
        return head;
    }
};

//APPROACH-2


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        //Boundary cases
        if(!head)
            return head;
        
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *odd_head = head;
        ListNode *even_head = head->next;
        
        while(even && even->next)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = even_head;        
        return head;
    }
};

 
 
