// jai shree ram

set<vector<int>> ans;
void f(int i , vector<int> &A , int x , vector<int> &v) {
    if(i == A.size()) {
        if(x == 0) {
            ans.insert(v);
        }
        return ;
    }
    if(x - A[i] >= 0) {
        v.push_back(A[i]);
        f(i+1 , A, x - A[i] , v);
        v.pop_back();
    }
    f(i+1 , A , x , v);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    ans.clear();
    vector<int> v;
    f(0 , A , B , v);
    vector<vector<int>> V;
    for(auto it : ans) {
        V.push_back(it);
    }
    return V;
}
