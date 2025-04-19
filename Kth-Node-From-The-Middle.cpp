// jai shree ram
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) {
    int pos = 0;
    ListNode *slow = A , *fast = A;
    while(fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
        pos++;
    }
    int ind = pos - B;
    int i = 0;
    ListNode *node = A; 
    while(node) {
        if(i == ind) {
            return node -> val;
        }
        i++;
        node = node -> next;
    }
    return -1;
}
