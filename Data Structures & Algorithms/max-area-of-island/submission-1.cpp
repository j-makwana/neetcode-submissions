class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int m = grid.size() ;
        int n = grid[0].size();
        int ans = 0;
        for(int i =0; i< m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==1){
                    ans = max(ans, dfs(i,j, grid,m ,n));
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
    int dfs(int i, int j, vector<vector<int>> & grid, int m, int n){
        if(!boundary_check(i,j,m,n)|| grid[i][j]== 0 ){
            return 0;
        }
        grid[i][j]= 0;
        int down = dfs(i+1,j, grid, m,n);
        int up = dfs(i-1,j, grid, m,n);
        int right = dfs(i,j+1, grid, m,n);
        int left = dfs(i,j-1, grid, m,n);
        return (up + down + left + right+1);
    }
};
