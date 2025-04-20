// jai shree ram
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    ListNode *slow = A , *fast = A;
    while(fast && fast -> next) {
        slow = slow -> next;
        fast  = fast -> next -> next;    
    }
    // list l1 and l2
    ListNode *l1 = A;
    ListNode *l2 = slow;
    ListNode *dummy = new ListNode(-1);
    // reverse second list;
    ListNode *prev = NULL , *curr = l2 , *forw;
    while(curr) {
        forw  = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forw;
    }
    l2 = prev;
    ListNode *ans = dummy;
    int i = 0;
    while(l1 && l2) {
        if(i%2==0) {
            dummy -> next = l1;
            l1 = l1 -> next;
        }
        else {
            dummy -> next = l2;
            l2 = l2 -> next;
        }
        i++;
        dummy = dummy -> next;
    }
    return ans -> next;
}
