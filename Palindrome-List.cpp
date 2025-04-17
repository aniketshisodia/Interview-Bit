// jai shree ram
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    
    // check if no node or one node
    if(!A || !A->next){
        return 1;
    }
    
    // find the middle element
    ListNode *slow = A, *fast = A;
    while(fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    ListNode*prev=NULL , *curr = slow , *forw;
    while(curr) {
        forw = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forw;
    }
    
    // compare first half and 2nd half
    
    // example test case -> :
    
    // 1 2 3 2 1 
    // 1->2->3 and 1->2->3 bcoz odd linked list next will not be changed
    ListNode *front=A;
    ListNode *back = prev;
    
    while(back) {
        if(front -> val != back -> val) {
            return 0;
        }
        back = back -> next;
        front = front -> next;
    }
    return 1;
    
}
