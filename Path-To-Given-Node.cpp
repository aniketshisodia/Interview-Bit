// jai shree ram
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> ans; 
void dfs(TreeNode *node , int x , vector<int> path) {
    if(ans.size()) 
    return;
    if(!node)
    return;
    if(node -> val == x) {
        path.push_back(node -> val);
        ans = path;
        return;
    }
    path.push_back(node -> val);
    dfs(node -> left , x , path);
    dfs(node -> right , x , path);
    path.pop_back();    
}
vector<int> Solution::solve(TreeNode* A, int B) {
    ans.clear();
    vector<int> path;
    dfs(A , B , path);
    return ans;
}
