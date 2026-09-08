class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtrack(curr, ans, nums, 0);
        return ans;
        
    }
    void backtrack(vector<int>& curr, vector<vector<int>>& ans, vector<int>&nums, int i){
        if(i==nums.size()){
            ans.push_back(curr);
            return;
        }
        ans.push_back(curr);
        for(int j =i; j< nums.size();j++){
            if(j > i && nums[j-1]==nums[j]){
                continue;
            }
            curr.push_back(nums[j]);
            backtrack(curr, ans, nums, j+1);
            curr.pop_back();
            
        }
    }
};
