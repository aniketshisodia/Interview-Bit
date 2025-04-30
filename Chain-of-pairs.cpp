// jai shree ram

int dp[1001][1001];

int f(int i , int prevInd ,vector<vector<int>> &A) {
    if(i == A.size()) {
        return 0;
    }
    if(dp[i][prevInd + 1] != -1) {
        return dp[i][prevInd + 1];
    }
    // include this element
    int  inc = 0 , exc = 0;
    if(prevInd == -1 || A[i][0] > A[prevInd][1]) {
        inc = 1 + f(i + 1 , i , A);
    }
    exc = f(i + 1 , prevInd , A);
    return dp[i][prevInd + 1] = max(inc , exc);
}

int Solution::solve(vector<vector<int> > &A) {
    memset(dp , -1 , sizeof(dp));
    return f(0  , -1 , A);
}
