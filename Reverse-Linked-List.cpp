// jai shree ram
ListNode* Solution::reverseList(ListNode* A) {
    ListNode *prev = NULL , *curr = A , *forw;
    while(curr != NULL) {
        forw = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forw;
    }
    return prev;
}
