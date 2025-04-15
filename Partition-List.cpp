// jai shree ram
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode *smallHead = NULL;
    ListNode *largeHead = NULL;
    ListNode *head = A;
    
    while(head) {
        if(head -> val < B && smallHead == NULL) smallHead = head;
        if(head -> val >= B && largeHead == NULL) largeHead = head;
        head = head -> next;
    }
       
    if(!smallHead) return largeHead;
    if(!largeHead) return smallHead;
    
    ListNode *node = new ListNode(0);
    ListNode *save = node;
    head = A;
    while(head) {
        if(head -> val < B) {
            node -> next = new ListNode(head -> val);
            node = node -> next;
        }
        head = head -> next;
    }
    head = A;
    while(head) {
        if(head -> val >= B) {
            node -> next = new ListNode(head -> val);
            node = node -> next;
        }
        head = head -> next;
    }
    return save -> next;
}
