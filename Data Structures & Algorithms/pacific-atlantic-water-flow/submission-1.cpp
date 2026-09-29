class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int m = heights.size();
        int n = heights[0].size();
        /// I want to check for whteher top
        ///row = 0, col = c
        set<pair<int,int>> pacific;
        set<pair<int,int>> atlantic;
        for(int j =0; j<n;j++){
            dfs(0,j, m,n, pacific, heights[0][j], heights);
            dfs(m-1, j, m,n, atlantic, heights[m-1][j], heights);

        }
        ///row = varying, col = 0
        ///row = varying, col = n-1

        for(int i =0; i<m;i++){
            dfs(i,0, m,n, pacific, heights[i][0], heights);
            dfs(i, n-1 , m,n, atlantic, heights[i][n-1], heights);
        }
        for(int r = 0; r <m; r++){
            for(int c=0; c<n;c++){
                ////check if this exists in both the sets
                if(pacific.contains({r,c})&& atlantic.contains({r,c})){
               
                    ans.push_back({r,c});
                }
            }
        } 

        return ans;
    }
    bool valid(int r, int c, int m, int n) {
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return false;
        }
        return true;
    }
    void dfs(int r, int c, int m, int n, set<pair<int, int>>& visited, int prevHeight,
             vector<vector<int>>& heights) {
        /// base case
        /// if r and c are invalid, stop. If it is in visited, stop
        ///  if r,c > prevHeigh, stop

        if (!valid(r, c, m, n) || visited.contains({r, c}) || heights[r][c] < prevHeight) {
            return;
        }
        /// add to visited
        visited.insert({r, c});
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for (pair<int, int>& val : directions) {
            int new_r = r + val.first;
            int new_c = c + val.second;
            dfs(new_r, new_c, m, n, visited, heights[r][c], heights);
        }
    }
};
