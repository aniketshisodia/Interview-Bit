// jai shree ram
vector<vector<int>> dp;

int f(int i, int j, string &A, string &B) {
    if(i == A.size() && j == B.size()) return 0;
    if(i == A.size()) return B.size() - j;
    if(j == B.size()) return A.size() - i;

    if(dp[i][j] != -1) return dp[i][j];

    if(A[i] == B[j]) {
        return dp[i][j] = f(i + 1, j + 1, A, B);
    }

    int op1 = 1 + f(i + 1, j + 1, A, B); // Replace
    int op2 = 1 + f(i + 1, j, A, B);     // Delete
    int op3 = 1 + f(i, j + 1, A, B);     // Insert

    return dp[i][j] = min({op1, op2, op3});
}

int Solution::minDistance(string A, string B) {
    int n = A.size(), m = B.size();
    dp.clear();
    dp.resize(n + 1, vector<int>(m + 1, -1));
    return f(0, 0, A, B);
}
