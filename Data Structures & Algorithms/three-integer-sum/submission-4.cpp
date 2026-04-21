class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector <int>> result;
        
        sort(nums.begin(), nums.end());
        for(int i =0; i< nums.size();i++){
        
            int first = nums[i];
            if(i>0 && first==nums[i-1]){
                continue;
            }
            int left = i+1;
            int right = nums.size()-1;
            int target = -first;
            while(left<right){
                int toCheck = nums[left]+nums[right];
                if(toCheck == target){
                    result.push_back({first, nums[left], nums[right]});
                    while(left<right && nums[right-1]== nums[right]){
                        right--;
                    };
                }
                if(toCheck < target){
                    left++;
                }else{
                    right--;
                }
            }

            
        }
        return result;
    }
};
