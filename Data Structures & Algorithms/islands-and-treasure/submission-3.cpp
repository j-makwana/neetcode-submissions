class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) { 
        int m= grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> myQueue;

        for(int i =0; i<m;i++){
            for(int j =0; j<n;j++){
                if(grid[i][j]==0){
                    myQueue.push({i,j});
                }
            }
        }
        
    bfs(grid, myQueue);
    
    
     }
    void bfs(vector<vector<int>>& grid, queue<pair<int, int>>& myQueue) {
        vector<pair<int, int>> iterate = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        
        set<pair<int, int>> visited;
        int ans = 0;
        while (!myQueue.empty()) {
            int q_size = myQueue.size();
            for (int i = 0; i < q_size; i++) {
                int r = myQueue.front().first;
                int c = myQueue.front().second;
                myQueue.pop();
                if(!valid(r,c,grid.size(), grid[0].size()) || grid[r][c]==-1){
                    continue;
                }
                if (!visited.contains({r, c})) {
                    visited.insert({r, c});
                    grid[r][c] = min(ans, grid[r][c]);
                    for (pair<int, int> val : iterate) {
                        int new_r = r + val.first;
                        int new_c = c + val.second;
                        if (!visited.contains({new_r, new_c}) && valid(new_r,new_c, grid.size(), grid[0].size())) {
                            myQueue.push({new_r, new_c});
                        }
                    }
                }
            }
            ans += 1;
        }
    }
    bool valid(int r, int c, int r_max, int c_max) {
        if (r < 0 || r >= r_max || c < 0 || c >= c_max) {
            return false;
        }
        return true;
    }
};
