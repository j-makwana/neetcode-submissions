class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> myset;
        for(int i=0;i< nums.size(); i++){
            if(myset.contains(nums[i])){
                return true;
            }else{
                myset.insert(nums[i]);
            }
        }
        return false;
        
    }
};