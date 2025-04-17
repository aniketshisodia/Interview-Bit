// JAI SHREE RAM
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *dummy = new ListNode(-1);
    ListNode *tail = dummy;
    ListNode *head = A;
    
    while (head) {
        int value = head->val;
        int count = 0;
        ListNode* temp = head;

        // Count duplicates
        while (head && head->val == value) {
            head = head->next;
            count++;
        }

        // Only add node if it was not duplicated
        if (count == 1) {
            tail->next = temp;
            tail = tail->next;
            tail->next = nullptr; // very important to avoid linking to a duplicate node
        }
    }
    
    return dummy->next;
}
