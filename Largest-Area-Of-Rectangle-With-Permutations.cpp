int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    if (n == 0) return 0;
    int m = A[0].size();

    vector<vector<int>> height(n, vector<int>(m, 0));

    // Step 1: Build height matrix
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (A[i][j] == 0)
                height[i][j] = 0;
            else
                height[i][j] = (i > 0 ? height[i - 1][j] + 1 : 1);
        }
    }

    int maxArea = 0;

    // Step 2: Sort each row and calculate max area
    for (int i = 0; i < n; ++i) {
        sort(height[i].begin(), height[i].end(), greater<int>());
        for (int j = 0; j < m; ++j) {
            int area = height[i][j] * (j + 1);
            maxArea = max(maxArea, area);
        }
    }

    return maxArea;
}
