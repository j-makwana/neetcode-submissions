class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int r_b = board.size();
        int c_b = board[0].size();
        bool ans = false;
        for(int i =0; i< r_b; i++){
            for(int j =0; j< c_b; j++){
                if(board[i][j]==word[0]){
                    set<pair<int,int>> visited;
                    //visited.insert({i,j});
                   ans = backtrack(board, word,visited,i,j,r_b,c_b, 0);
                   if(ans){
                    return true;
                   }

                }
            }
        }
        return ans;

    }
    bool border(int r, int c, int r_b, int c_b){
        return ((r<r_b) && (r>=0) && (c>=0) && (c<c_b));
    }
    bool backtrack(vector<vector<char>>&board, string word, set<pair<int,int>> visited, int r, int c, int r_b, int c_b, int idx){
        if(idx == word.size()){
            return true;
        }
        if(border(r,c,r_b,c_b)&& !visited.contains({r,c}) && board[r][c]==word[idx]){
            visited.insert({r,c});
            bool down = backtrack(board,word,  visited, r+1,c,r_b,c_b, idx+1);
            bool up = backtrack(board,word,  visited, r-1,c,r_b,c_b, idx+1);
            bool right = backtrack(board,word,visited, r,c+1,r_b,c_b, idx+1);
            bool left = backtrack(board,word,  visited, r,c-1,r_b,c_b, idx+1);
            return (down || up || right || left);
        }
        return false;
    }

};
