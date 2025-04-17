// jai shree ram
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *node = A;
    ListNode *ans = new ListNode(-1);
    ListNode *store = ans;
    while(A) {
        int val = A -> val;
        ListNode *temp;
        while(A && A -> val == val) {
            temp = A;
            A = A->next;
        }
        ans -> next = temp;
        ans = ans -> next;
    }
    return store -> next;
}
