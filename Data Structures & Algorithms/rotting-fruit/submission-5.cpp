class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> add = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        queue<pair<int, int>> myq;
        set<pair<int, int>> visited;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    myq.push({i, j});
                }
            }
        }
        int dist = -1;
        while (!myq.empty()) {
            int q_size = myq.size();
            for (int k = 0; k < q_size; k++) {
                int r = myq.front().first;
                int c = myq.front().second;
                myq.pop();
                visited.insert({r, c});
                for (pair<int, int> val : add) {
                    int new_r = r + val.first;
                    int new_c = c + val.second;
                    if (valid(new_r, new_c, m, n, visited, grid)) {
                        //mark it as 2
                        grid[new_r][new_c]=2;
                        myq.push({new_r, new_c});
                    }
                }
            }
            dist++;
            
        }
       
        for(vector<int>& values: grid){
            for(int& val: values){
                  if(val==1){
                return -1;
            }
            }
          
        }
        if(dist == -1){
            return 0;
        }
        return dist;
    }
        bool valid(int r, int c, int r_max, int c_max, set<pair<int, int>>& visited,
                   vector<vector<int>>& grid) {
            if (r < 0 || r >= r_max || c < 0 || c >= c_max || visited.contains({r, c}) ||
                grid[r][c] != 1) {
                return false;
            }
            return true;
        }
    };
