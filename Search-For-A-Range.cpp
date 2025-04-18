// jai shree ram
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int low = 0 , high = A.size()-1;
    int f = 0;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(A[mid] == B) {
            f = 1;
            break;
        }
        else 
        if(A[mid] < B) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    if(!f) {
        return {-1,-1};
    }
    return {lower_bound(A.begin(),A.end(),B) - A.begin() , upper_bound(A.begin(),A.end(),B)-A.begin()-1};
}
