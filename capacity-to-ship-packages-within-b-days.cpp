// jai shree ram
#define ll long long
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
        
    ll low = *max_element(A.begin() , A.end()) , high = 1e18;
    
    int ans = 1e18;
    
    while(low <= high) {
    
        ll mid = (low + high) / 2;
    
        int days = 1;
        
        ll sum = 0;
        
        for(int i = 0 ; i < n; i++) {
            sum  += A[i];
            if(sum > mid) {
                sum = A[i];
                days++;
            }
        }
        
        if(days <= B) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}
