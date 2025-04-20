// jai shree ram
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    int c = 0;
    ListNode *node = new ListNode(-1);
    ListNode *ans = node;
    
    while (A || B || c) {
        int sum = c;
        if (A) {
            sum += A->val;
            A = A->next;
        }
        if (B) {
            sum += B->val;
            B = B->next;
        }
        c = sum / 10;
        node->next = new ListNode(sum % 10);
        node = node->next;
    }
    return ans->next;
}
