// jai shree ram
ListNode* Solution::swapPairs(ListNode* A) {
    if(!A || !A->next) {
        return A;
    }
    ListNode *node = A;
    ListNode *dummy = new ListNode(0);
    dummy -> next = A;
    ListNode *prev = dummy;
    while(prev -> next && prev -> next -> next) {
        ListNode *first = prev -> next;
        ListNode *second = first -> next;
        
        // swapPairs
        first -> next = second -> next;
        second -> next = first;
        prev -> next = second;
        
        prev = first;
    }
    return dummy->next;
}
