vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    
    vector<int> ans;
    
    int count = 0;
    int total = m*n;
    int startRow = 0 , endRow = n-1 , startCol = 0 , endCol = m-1;
    
    while(count < total) {
        for(int i = startCol ; count < total && i <= endCol; i++) {
            ans.push_back(A[startRow][i]);
            count++;
        }
        startRow++;

        for(int i = startRow; count < total && i <= endRow; i++) {
            ans.push_back(A[i][endCol]);
            count++;
        }
        endCol--;

        for(int i = endCol; i >= startCol && count < total; i--) {
            ans.push_back(A[endRow][i]);
            count++;
        }
        endRow--;

        for(int i = endRow; i >= startRow && count < total; i--) {
            ans.push_back(A[i][startCol]);
            count++;
        }
        startCol++;        
    }
    return ans;
}
