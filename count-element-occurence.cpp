// jai shree ram

// find if element do exist or not
// if do exist find upper and lower bounds..

int bs1(vector<int> &A , int x) {
    int n = A.size();
    int low = 0 , high = n-1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        
        if(A[mid] == x) {
            return 1;
        }
        else
        if(A[mid] > x) {
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return 0;
}


int Solution::findCount(const vector<int> &A, int B) {
    vector<int> a = A;
    int f = bs1(a , B);
    if(!f) return 0;
    return upper_bound(a.begin() , a.end() , B) - lower_bound(a.begin() , a.end() , B);
}
