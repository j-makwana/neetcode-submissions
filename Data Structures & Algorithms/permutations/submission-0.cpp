class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(curr, ans, nums);
        return ans;

    }
    void backtrack(vector<int>& curr, vector<vector<int>> &ans, vector<int> &nums){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
        }
        for(int i =0; i< nums.size(); i++){
            if(find(curr.begin(), curr.end(), nums[i])== curr.end()){
                //if it is not already there
                curr.push_back(nums[i]);
                backtrack(curr, ans, nums);
                curr.pop_back();

            }
        }
    }
};
