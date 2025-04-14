// jai shree ram

vector<vector<int>> ans;

void f(vector<int> &A , int i , vector<int> s) {
    if(i == A.size()) {
        ans.push_back(s);
        return;
    }
    f(A , i+1 , s);
    // inc
    s.push_back(A[i]);
    f(A , i+1 , s);
    s.pop_back();
    // exc
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    ans.clear();
    sort(A.begin(),A.end());
    vector<int> s;
    f(A , 0 , s);
    sort(ans.begin(),ans.end());
    return ans;
}
