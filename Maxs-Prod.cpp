// jai shree ram
int Solution::maxSpecialProduct(vector<int> &A) {
    int n = A.size();
    vector<long long> left(n, 0), right(n, 0);
    stack<int> st;

    // LeftSpecialValue
    for (int i = 0; i < n; i++) {
        while (!st.empty() && A[st.top()] <= A[i]) {
            st.pop();
        }
        if (!st.empty()) {
            left[i] = st.top();
        }
        st.push(i);
    }

    // Clear the stack for reuse
    while (!st.empty()) st.pop();

    // RightSpecialValue
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && A[st.top()] <= A[i]) {
            st.pop();
        }
        if (!st.empty()) {
            right[i] = st.top();
        }
        st.push(i);
    }

    long long maxProduct = 0;
    long long mod = 1e9 + 7;

    for (int i = 0; i < n; i++) {
        maxProduct = max(maxProduct, left[i] * right[i]);
    }

    return maxProduct % mod;
}
