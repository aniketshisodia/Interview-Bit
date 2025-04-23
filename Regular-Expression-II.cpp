    // jai shree ram
    int Solution::isMatch(const string A, const string B) {
        int n = A.size();
        int m = B.size();
        
        vector<vector<int>> dp(n+1 , vector<int> (m+1 , 0));
        
        dp[0][0] = 1;
        
        for(int j=2; j <= m; ++j) {
            if(B[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }    
        }
        
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(B[j - 1] == '.' || B[j - 1] == A[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else 
                if(B[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                    if(B[j - 2] == A[i - 1] || B[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }
        return dp[n][m] ? 1 : 0;
    }
