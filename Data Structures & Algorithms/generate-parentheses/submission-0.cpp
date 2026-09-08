class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        string curr;
        vector<string> ans;
        backtrack(curr, ans, n, n);

        return ans;
    }
    void backtrack(string& curr, vector<string>& ans, int count_left, int count_right) {
        if (count_left == 0 && count_right == 0) {
            ans.push_back(curr);
            return;
        }
        if (count_right < count_left) {
            return;
        }
        if (count_left > 0) {
            curr += '(';
            backtrack(curr, ans, count_left - 1, count_right);
            curr.pop_back();
        }
        if (count_right > 0) {
            curr += ')';
            backtrack(curr, ans, count_left, count_right - 1);
            curr.pop_back();
        }
    }
};
