// jai shree ram
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    // count number of nodes;
    if(B == 1 || !A || !A->next || B == 0) {
        return A;
    }
    ListNode *node = A;
    int totalNodes=0;
    while(node) {
        totalNodes++;
        node = node -> next;
    }
    int times = totalNodes/B;
    ListNode *ans = NULL , *LastNode=NULL;
    ListNode *prev = NULL , *curr = A , *forw = NULL;
    
    for(int i = 1; i <= times; i++) {
        // reverse a linked list
        int k=B;
        prev = NULL;
        ListNode *x = curr;
        while(k--) {
            forw = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forw;            
        }
        if(i == 1) {
            ans = prev;
        }
        if(i > 1) {
            LastNode -> next = prev;
        }
        LastNode = x;
    }
    return ans;
}
