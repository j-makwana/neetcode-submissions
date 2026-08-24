class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 1;
        int first_val = nums[0];
        for(int i =1; i< nums.size();i++)
        {
           if(nums[i]==first_val){
            counter ++;
           }else{
            counter --;
            if(counter ==0){
                first_val = nums[i];
                counter = 1;
            }
            
           }
        }
    
    return first_val;
    }
};