// jai shree ram
string Solution::solve(string A) {
    int n = A.size();
    queue<char> q;
    map<char,int> mp;
    string ans;
    for(int i = 0 ; i < n ; i++) {
        mp[A[i]]++;
        if(i == 0) {
            ans.push_back(A[i]);
            q.push(A[i]);
            continue;
        }
        while(q.size() && mp[q.front()] > 1) {
            q.pop();
        }
        if(mp[A[i]] == 1) {
            q.push(A[i]);
        }
        if(q.empty()) ans.push_back('#');
        else ans.push_back(q.front());
    }
    return ans;
}
