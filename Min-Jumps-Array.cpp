// jai shree ram
int Solution::jump(vector<int> &A) {
    int n = A.size();
    if(n <= 1) {
        return 0;
    }
    int farthest = 0 , curr_end = 0 , jumps = 0;
    for(int i = 0 ; i < n; ++i) {
        farthest = max(farthest , A[i] + i);
        
        if(i == curr_end) {
            jumps++;
            curr_end = farthest;
            if(curr_end >= n-1)
                return jumps;
        }            
    }
    return -1;
}
