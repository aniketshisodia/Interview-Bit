// jai shree ram
int Solution::chordCnt(int A) {
    const int MOD = 1e9 + 7;
    vector<long long> dp(A + 1, 0);
    dp[0] = 1; // 0 chords -> 1 way (empty)

    for (int i = 1; i <= A; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = (dp[i] + dp[j] * dp[i - 1 - j]) % MOD;
        }
    }
    return dp[A];
}
