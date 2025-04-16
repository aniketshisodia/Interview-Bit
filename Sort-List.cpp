// jai shree ram
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* merge(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    ListNode* head = nullptr;

    if (l1->val < l2->val) {
        head = l1;
        l1 = l1->next;
    } else {
        head = l2;
        l2 = l2->next;
    }

    ListNode* tail = head;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = l1 ? l1 : l2;
    return head;
}

ListNode* findMid(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* Solution::sortList(ListNode* head) {
    if (!head || !head->next)
        return head;

    ListNode* mid = findMid(head);
    ListNode* right = sortList(mid->next);
    mid->next = nullptr;
    ListNode* left = sortList(head);

    return merge(left, right);
}
