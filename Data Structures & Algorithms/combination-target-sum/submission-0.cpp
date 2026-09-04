class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
     vector<vector<int>> ans;
     vector<int> curr;
     backtrack(curr, ans, nums, 0, target);
     return ans;

    }
    void backtrack(vector<int>& curr, vector<vector<int>>&ans,vector<int>&nums, int i, int target){
        
       if(target ==0){
        //add curr to ans
        ans.push_back(curr);
        return;
       }
       if(target < 0){
        return;
       }
        
       for(int j = i; j<nums.size(); j++){
        ///
        if((target - nums[j])>=0){
            curr.push_back(nums[j]);
            backtrack(curr, ans, nums, j , target-nums[j]);
            curr.pop_back();

        }
        
       }

    }
};
