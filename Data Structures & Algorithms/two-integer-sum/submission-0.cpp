class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> differencehp;
        for(int i=0;i<nums.size(); i++){
            int n = nums[i];
            if(differencehp.contains(target-n)){
                return {differencehp[target-n],i};
            }
            differencehp[n] = i;



        }

        
    }
};
