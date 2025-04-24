// jai shree ram

int dp[100001][4];
int f(int i , int prev_col , vector<vector<int>> &A) {
    if(i == A.size()) {
        return 0;
    }
    
    if(dp[i][prev_col + 1] != -1) {
        return dp[i][prev_col + 1];
    }
    
    int res = INT_MAX;
    
    for(int col = 0 ; col < 3; col++) {
        if(prev_col != col) {
            int x = A[i][col] + f(i+1 , col , A);
            res = min(x , res);
        }
    }
    
    return dp[i][prev_col + 1] = res;
}


int Solution::solve(vector<vector<int> > &A) {
    memset(dp , -1 , sizeof(dp));
    return f(0 , -1 , A);
}
