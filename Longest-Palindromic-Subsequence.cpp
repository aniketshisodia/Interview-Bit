// jai shree ram
int Solution::solve(string A) {
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
        dp[i][i] = 1;

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (A[i] == A[j])
                dp[i][j] = 2 + (len == 2 ? 0 : dp[i + 1][j - 1]);
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    return dp[0][n - 1];
}
