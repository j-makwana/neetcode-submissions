class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> curr;
        for(int i=0; i< n; i++){
            string a = ".";
                for(int j =1; j < n;j++){
                    a+=".";
                }
            curr.push_back(a);
        }
        vector<vector<string>> ans;
        set<int> col;
        set<int> posDiag;
        set<int> negDiag;


        backtrack(0, ans, col, posDiag, negDiag, curr, n);
        return ans;
    }
  
    void backtrack(int r, vector<vector<string>>& ans, set<int>& col, set<int>&posDiag, set<int> &negDiag, vector<string> curr, int n){
        if(r==n){
            ans.push_back(curr);
            return;
        }
        for(int c=0; c<n;c++){
            if(col.count(c)<=0 && posDiag.count(r+c)<=0 && negDiag.count(r-c)<=0){
                ////if it is not there append the stuff
                col.insert(c);
                posDiag.insert(r+c);
                negDiag.insert(r-c);
                curr[r][c] = 'Q';
                backtrack(r+1,ans, col, posDiag, negDiag, curr,n);
                col.erase(c);
                posDiag.erase(r+c);
                negDiag.erase(r-c);
                curr[r][c]= '.';
            }


        } 

    }
};
