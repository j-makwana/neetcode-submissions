class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        backtrack(cur, ans, candidates, 0, target);
        return ans;
    }
    void backtrack(vector<int>& cur, vector<vector<int>>& ans, vector<int>& candidates, int i,
                   int target) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }

        for (int j = i; j < candidates.size(); j++) {
            if (j > i && candidates[j - 1] == candidates[j]) {
                continue;
            }
            if ((target - candidates[j]) >= 0) {
                cur.push_back(candidates[j]);
                backtrack(cur, ans, candidates, j + 1, target - candidates[j]);
                cur.pop_back();
            }
        }
    }
};
