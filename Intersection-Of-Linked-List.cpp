// jai shree ram
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    unordered_map<ListNode* , int> mp;
    while(A != NULL) {
        mp[A]++;
        A = A -> next;
    }
    while(B != NULL) {
        if(mp.count(B)) {
            return B;
        }
        B = B -> next;
    }
    return NULL;
}
