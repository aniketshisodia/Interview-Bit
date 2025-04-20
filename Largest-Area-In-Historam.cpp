// jai shree ram
int Solution::largestRectangleArea(vector<int> &A) {
    stack<int> st;
    int n = A.size();
    vector<int> prev(n, -1), next(n, -1);

    for (int i = 0; i < n; i++) {
        while (!st.empty() && A[st.top()] >= A[i]) {
            st.pop();
        }
        if (!st.empty()) {
            prev[i] = st.top();
        }
        st.push(i);
    }

    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && A[st.top()] >= A[i]) {
            st.pop();
        }
        if (!st.empty()) {
            next[i] = st.top();
        }
        st.push(i);
    }

    int maxi = 0;
    for (int i = 0; i < n; i++) {
        int h = A[i];
        int right = next[i] == -1 ? n : next[i];
        int width = right - prev[i] - 1;
        int area = h * width;
        maxi = max(maxi, area);
    }

    return maxi;
}
