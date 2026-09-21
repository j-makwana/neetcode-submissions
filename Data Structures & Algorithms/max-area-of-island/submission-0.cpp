class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int m = grid.size() ;
        int n = grid[0].size();
        int ans = 0;
        set<pair<int,int>> visited;
        for(int i =0; i< m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==1 && !visited.contains({i,j})){
                    ans = max(ans, dfs(i,j,visited, grid,m ,n));
                }
            }
        }
        return ans;
    }
    bool boundary_check(int r, int c, int m, int n){
        if(r<0 || r>= m || c<0 || c>=n){
            return false;
        }
        return true;
    }
    int dfs(int i, int j, set<pair<int,int>>& visited, vector<vector<int>> & grid, int m, int n){
        if(!boundary_check(i,j,m,n)|| grid[i][j]== 0 || visited.contains({i,j})){
            return 0;
        }
        visited.insert({i,j});
        int down = dfs(i+1,j,visited, grid, m,n);
        int up = dfs(i-1,j,visited, grid, m,n);
        int right = dfs(i,j+1,visited, grid, m,n);
        int left = dfs(i,j-1,visited, grid, m,n);
        return (up + down + left + right+1);
    }
};
