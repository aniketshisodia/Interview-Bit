// jai shree ram
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode *dummy = new ListNode(0);
    dummy -> next = A;
    ListNode *prev = NULL , *curr = A , *forw;
    ListNode *first = dummy , *last = dummy;
    
    int i = 1;
    
    ListNode *start = A;
    
    while(i < B) {
        first = curr;
        start = curr -> next;
        curr = curr -> next;
        i++;
    }
    
    while(i <= C) {
        forw = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forw;
        i++;
    }
    start -> next = curr;
    first -> next = prev;
    return dummy -> next;    
}
  
