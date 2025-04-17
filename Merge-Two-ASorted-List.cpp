// jai shree ram
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    //if one list is NULL return other one
    if(!A) return B;
    if(!B) return A;
    
    ListNode *ans = new ListNode(-1);
    ListNode *store = ans;
    
    while(A && B) {
        if(A -> val <= B -> val) {
            ans -> next = A;
            ans = ans -> next;
            A = A -> next;
        }
        else {
            ans -> next = B;
            ans = ans -> next;
            B = B -> next;
        }
    }
    
    if(A) {
        ans -> next = A;
    }
    if(B) {
        ans -> next = B;
    }
    return store -> next;    
}
