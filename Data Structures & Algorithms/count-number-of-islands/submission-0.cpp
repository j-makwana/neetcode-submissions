class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
       set<pair<int,int>> visited;
       int ans = 0;
       int m = grid.size();
       int n = grid[0].size();
       for(int i = 0; i< m ;i++){
        for(int j = 0; j<n; j++){
            if(grid[i][j]=='1' && !visited.contains({i,j})){
                ans++;
                dfs(i,j,visited,grid,m,n);

            }
        }
       }
       return ans;
    }
    bool boundary_check(int r, int c, int m, int n){
        if(r<0 || r >=m || c<0 || c>=n){
            return false;
        }
        return true;
    }
    void dfs(int i, int j, set<pair<int,int>>& visited, vector<vector<char>>& grid, int m, int n){
        if(!boundary_check(i, j, m, n) || grid[i][j] == '0' || visited.contains({i,j})){
            return;
        }

        visited.insert({i,j});
        dfs(i+1,j, visited, grid, m, n);
        dfs(i-1,j, visited, grid, m, n);
        dfs(i, j+1 ,visited, grid, m, n);
        dfs(i,j-1 ,visited, grid, m, n);


    }

};
