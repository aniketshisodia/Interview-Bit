// jai shree ram

vector<string> ans;

void f(vector<string> &A , string s , int index , int size) {
    if(index == A.size()) {
        ans.push_back(s);
        return;
    }
    
    for(int i = 0 ; i < A[index].size(); i++) {
        s.push_back(A[index][i]);
        f(A , s , index+1,size);
        s.pop_back();
    }
}

vector<string> Solution::specialStrings(vector<string> &A) {
    int size = A[0].size();
    ans.clear();
    f(A , "" , 0 , size);
    return ans;
}
