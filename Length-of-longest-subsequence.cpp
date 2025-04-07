int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n = A.size();
    if (n == 0) return 0;

    vector<int> inc(n, 1), dec(n, 1);

    // Compute LIS ending at each index
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {
                inc[i] = max(inc[i], inc[j] + 1);
            }
        }
    }

    // Compute LDS starting at each index
    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (A[i] > A[j]) {
                dec[i] = max(dec[i], dec[j] + 1);
            }
        }
    }

    // Combine LIS and LDS for longest bitonic subsequence
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, inc[i] + dec[i] - 1);
    }

    return maxi;
}
