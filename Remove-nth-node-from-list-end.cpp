// jai shree ram
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    if (A == NULL || A->next == NULL) {
        return NULL;
    }

    int n = 0;
    ListNode* node = A;
    while (node) {
        n++;
        node = node->next;
    }

    int pos = n - B;
    if (pos <= 0) {
        return A->next; // Delete head if B >= n
    }

    node = A;
    for (int i = 1; i < pos; i++) {
        node = node->next;
    }

    // if (node->next) {
        node->next = node->next->next;
    // }

    return A;
}
