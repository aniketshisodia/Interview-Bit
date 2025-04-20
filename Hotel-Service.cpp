// jai shree ram
vector<int> Solution::nearestHotel(vector<vector<int> > &A, vector<vector<int> > &B) {
    int n = A.size() , m = A[0].size();
    vector<vector<int>> dis(n , vector<int> (m , INT_MAX)) , vis(n , vector<int> (m , 0));
    
    queue<pair<pair<int,int>,int>> q;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(A[i][j]) {
                q.push({{i , j},0});
                dis[i][j] = 0;
            }
        }
    }
    
    int drow[4] = {-1 , 0 , 1 , 0};
    int dcol[4] = {0 , 1 , 0 , -1};
    
    while(q.size()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int distance = q.front().second;
        q.pop();
        
        for(int s = 0 ; s < 4; s++) {
            int nrow = drow[s] + r;
            int ncol = dcol[s] + c;
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && dis[nrow][ncol] > 1 + distance) {
                dis[nrow][ncol] = 1 + distance;
                q.push({{nrow , ncol} , dis[nrow][ncol]});
            }
        }
    }
    
    vector<int> ans;
    
    for(auto it : B) {
        int l = it[0] , r = it[1];
        l-- , r--;
        ans.push_back(dis[l][r]);
    }
    
    return ans;
    
}
