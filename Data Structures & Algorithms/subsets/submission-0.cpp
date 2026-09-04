class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> curr = {};
    backtrack(curr, ans, nums, 0);
    return ans;     
        
    }
    
    void backtrack(vector<int> &curr, vector<vector<int>>&ans, vector<int> & nums, int i){
        if(i>nums.size()){
            return;
        }
        ans.push_back(curr);
        for(int j =i ; j<nums.size(); j++){
            if(find(curr.begin(), curr.end(), nums[j])== curr.end()){
                curr.push_back(nums[j]);
                backtrack(curr, ans, nums, j+1);
                curr.pop_back();

            }
        }
    }
};
