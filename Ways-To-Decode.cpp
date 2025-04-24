// jai shree ram
int mod = 1e9 + 7;
int Solution::numDecodings(string A) {
    int n = A.size();
    if (n == 0 || A[0] == '0') return 0;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;  // Empty string has one decoding
    dp[1] = 1;  // Non-zero single digit can be decoded in one way

    for (int i = 2; i <= n; ++i) {
        int oneDigit = A[i - 1] - '0';
        int twoDigit = stoi(A.substr(i - 2, 2));

        if (oneDigit >= 1 && oneDigit <= 9)
            dp[i] = (dp[i] + dp[i - 1]) % mod;

        if (twoDigit >= 10 && twoDigit <= 26)
            dp[i] = (dp[i] + dp[i - 2]) % mod;
    }

    return dp[n] % mod;
}
