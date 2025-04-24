// jai shree ram

int MOD = 1e9 + 7;
// SAW Solution : 
// i did , failed on hard testcase (did using BITMASKING DP)
int Solution::solve(int A) {
    if (A % 2 != 0) return 0;

    vector<long long> dp(A + 1, 0);
    dp[0] = 1;
    if (A >= 2) dp[2] = 3;

    for (int i = 4; i <= A; i += 2) {
        dp[i] = (4 * dp[i - 2] % MOD - dp[i - 4] + MOD) % MOD;
    }

    return dp[A];
}
