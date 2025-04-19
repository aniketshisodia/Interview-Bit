// jai shree ram
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    int totalNodes = 0;
    ListNode *node = A;
    while(node) {
        node=node->next;
        totalNodes++;
    }
    B = B % totalNodes;
    if(B == 0) {
        return A;
    }
    int pos = totalNodes - B;
    ListNode *head = A;
    node = A;
    int i = 1;
    while(node) {
        if(i == pos) {
            ListNode *head = node -> next;
            ListNode *curr = node -> next;
            node -> next = NULL;
            while(curr -> next) {
                curr = curr -> next;
            }
            curr -> next = A;
            return head; 
        }
        i++;
        node = node -> next;
    }
    return A;
}
