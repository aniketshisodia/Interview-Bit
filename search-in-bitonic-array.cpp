// jai shree ram
int Solution::solve(vector<int> &A, int B) {
    
    int n = A.size();
    
    // find the bitonic point
    int low = 0 , high = n-1 ;
    
    while(low < high) {
        int mid = low + (-low + high) / 2;
        if(A[mid] < A[mid + 1]) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    
    int x = low;
    low = 0; high = x;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(A[mid] == B) {
            return mid;
        }
        else
        if(A[mid] < B) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    low = x+1; high = n-1;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(A[mid] == B) {
            return mid;
        }
        else
        if(A[mid] < B) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}
