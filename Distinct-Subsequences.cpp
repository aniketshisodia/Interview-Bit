// jai shree ram

int dp[701][701];

int f(int i , int j , string &A , string &B) {
    if(j == B.size()) {
        return 1;
    }
    if(i == A.size()) {
        return 0;
    }
    if(dp[i][j] != -1) return dp[i][j];
    // equal 
    int take = 0 , notTake = 0;
    if(A[i] == B[j]) {
        take = f(i+1 , j+1 , A , B);
        notTake = f(i+1 , j , A , B);
    }
    else {
        notTake = f(i+1 , j , A , B);
    }
    
    return dp[i][j] = take + notTake;
}

int Solution::numDistinct(string A, string B) {
    int n = A.size();
    int m = B.size();
    memset(dp , -1 , sizeof(dp));
    return f(0 , 0 , A , B);
}
