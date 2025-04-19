// jai shree ram
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    
    if(!A || !A -> next) return A;
    
    ListNode *node1 = new ListNode(-1);
    ListNode *node2 = new ListNode(-1);
    
    ListNode *node = A;
    
    ListNode *a = node1 , *b = node2;
    // create two linked lists
    int i = 0;
    while(node) {
        if(i % 2 == 0){
            node1->next = node;
            node1 = node1 -> next;
        }
        else {
            node2->next = node;
            node2 = node2 -> next;
        }
        i++;
        node = node -> next;
    }

    if(i % 2 == 0) {
        node1 -> next = NULL;
    }
    else {
        node2 -> next = NULL;
    }
    
    //  reverse second link list
    ListNode *prev = NULL , *curr = b->next , *forw = NULL;
    while(curr) {
        forw = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forw;
    } 
    // merge both list
    ListNode *ans = new ListNode(-1);
    ListNode *storeAns = ans;
    a = a -> next;
    b = prev;
    i = 0;
    while(a && b) {
        if(i % 2 == 0) {
            ans -> next = a;
            ans = ans -> next;
            a = a->next;
        }
        else {
            ans -> next = b;
            ans = ans -> next;
            b = b->next;    
        }
        i++;
    }
    if(a) {
        ans -> next = a;
    }
    if(b) {
        ans -> next = b;
    }
    
    return storeAns->next;
}
// jai shree ram
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    
    if(!A || !A -> next) return A;
    
    ListNode *node1 = new ListNode(-1);
    ListNode *node2 = new ListNode(-1);
    
    ListNode *node = A;
    
    ListNode *a = node1 , *b = node2;
    // create two linked lists
    int i = 0;
    while(node) {
        if(i % 2 == 0){
            node1->next = node;
            node1 = node1 -> next;
        }
        else {
            node2->next = node;
            node2 = node2 -> next;
        }
        i++;
        node = node -> next;
    }

    if(i % 2 == 0) {
        node1 -> next = NULL;
    }
    else {
        node2 -> next = NULL;
    }
    
    //  reverse second link list
    ListNode *prev = NULL , *curr = b->next , *forw = NULL;
    while(curr) {
        forw = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forw;
    } 
    // merge both list
    ListNode *ans = new ListNode(-1);
    ListNode *storeAns = ans;
    a = a -> next;
    b = prev;
    i = 0;
    while(a && b) {
        if(i % 2 == 0) {
            ans -> next = a;
            ans = ans -> next;
            a = a->next;
        }
        else {
            ans -> next = b;
            ans = ans -> next;
            b = b->next;    
        }
        i++;
    }
    if(a) {
        ans -> next = a;
    }
    if(b) {
        ans -> next = b;
    }
    
    return storeAns->next;
}
