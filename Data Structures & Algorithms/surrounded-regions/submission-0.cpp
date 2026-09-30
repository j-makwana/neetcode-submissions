class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        set<pair<int,int>> visited;
        for(int j=0; j<n;j++){
            dfs(0,j, visited, board, m,n);
            dfs(m-1, j, visited, board, m, n);

        }
        for(int i =0; i<m;i++){
            dfs(i,0, visited, board,m,n);
            dfs(i, n-1, visited, board, m, n);

        }

        for(int r=0; r<m; r++){
            for(int c=0; c<n;c++){
                if(board[r][c]== 'O' && !visited.contains({r,c})){
                    board[r][c] = 'X';
                }
            }
        }
       

    }
    bool valid(int r, int c, int m, int n){
        if(r<0 || r>=m || c<0 || c>= n ){
            return false;
        }
        return true;
    }
    void dfs(int r, int c, set<pair<int,int>> & visited, vector<vector<char>>& board, int m, int n){
        if(!valid(r,c,m,n)|| board[r][c]=='X'|| visited.contains({r,c})){
            return;
        }
        visited.insert({r,c});
        vector<pair<int,int>> directions = {{0,1},{1,0}, {-1,0},{0,-1}};
        for(pair<int,int> dir: directions){
            int new_r = r+ dir.first;
            int new_c = c + dir.second;
            dfs(new_r, new_c, visited, board, m,n);
        }
    }
};
