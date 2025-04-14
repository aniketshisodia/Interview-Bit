// jai shree ram

vector<vector<int>> ans;

void f(int i , vector<int> &A , int x , vector<int> t) {
    if(i == A.size() || x < 0) {
        if(x == 0) {
            ans.push_back(t);
        }
        return;
    }
    if(x - A[i] >= 0) {
        t.push_back(A[i]);
        f(i , A , x - A[i] , t);
        t.pop_back();
    }
    f(i+1 , A , x , t);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    ans.clear();
    vector<int> t;
    vector<int> a;
    sort(A.begin() , A.end());
    a.push_back(A[0]);
    for(auto it : A) {
        if(a.back() != it) {
            a.push_back(it);
        }
    }
    f(0 , a , B , t);
    return ans;
}
