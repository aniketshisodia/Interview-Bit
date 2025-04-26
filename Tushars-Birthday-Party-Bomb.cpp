// jai shree ram
vector<int> Solution::solve(int A, vector<int> &B) {
    int n = B.size();
    int max_kicks = 0;
    int mini = INT_MAX;
    int min_index = -1;
    for(int i = 0 ; i < n; i++) {
        if(mini > B[i]) {
            mini = B[i];
            min_index = i;
        }
    }
    vector<int> ans;
    max_kicks = A / mini;
    while(max_kicks > 0) {
        for(int i = 0 ; i < n ; i++) {
            if(B[i] + B[min_index]*(max_kicks - 1) <= A) {
                ans.push_back(i);
                max_kicks--;
                A-=B[i];
                break;
            }
        }
    }
    return ans;
}
