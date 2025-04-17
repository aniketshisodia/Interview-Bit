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
    vector<int> a;
    while(A) {
        a.push_back(A->val);
        A=A->next;
    }
    int i = 0 ; int j = a.size()-1;
    while(i < j) {
        if(a[i] != a[j]) return 0;
        i++ , j--;
    }
    return 1;
}
