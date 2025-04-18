// jai shree ram

// Apply :
// Binary Search on ROW

// Then BS on COL
int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int low = 0 , high = A.size()-1;
    while(low <= high) {
        int midRow = (low + high) / 2;
        
        int lowCol = 0 , highCol = A[0].size()-1;
        
        while(lowCol <= highCol) {
            int midCol = (lowCol + highCol) / 2;
            
            if(A[midRow][midCol] == B) {
                return 1;
            }
            else
            if(A[midRow][midCol] < B) {
                lowCol = midCol + 1;
            }
            else {
                highCol = midCol - 1;
            }
        }
        if(A[midRow][0] > B) {
            high = midRow - 1;
        }
        else {
            low = midRow + 1;
        }
    }
    return 0;
}
