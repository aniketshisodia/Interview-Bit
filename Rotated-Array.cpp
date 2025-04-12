// jai shree ram
int Solution::findMin(const vector<int> &A) {
    int n = A.size();
    int low = 0 , high = n-1 , mini = INT_MAX;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(A[mid] < A[high]) {
            mini = min(A[mid] , mini);
            high = mid - 1;
        }
        else {
            mini = min(A[high] , mini);
            low = mid + 1;
        }
    }
    return mini;
}
