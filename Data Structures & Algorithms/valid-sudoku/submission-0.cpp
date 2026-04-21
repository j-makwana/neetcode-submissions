class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_map<int,set<char>> row;
        unordered_map<int,set<char>> col;
        unordered_map<int,set<char>> box;
        for(int i = 0;i< 9;i++){
            for(int j=0; j<9; j++){
                if(board[i][j]== '.'){
                    continue;
                }
                int boxIdx = (i/3)*3 + (j/3);
                if(row[i].contains(board[i][j]) || col[j].contains(board[i][j])|| box[boxIdx].contains(board[i][j])){
                    return false;
                }else{
                    row[i].insert(board[i][j]);
                    box[boxIdx].insert(board[i][j]);
                    col[j].insert(board[i][j]);
                }
            }
        }
        return true;
        
    }
};
