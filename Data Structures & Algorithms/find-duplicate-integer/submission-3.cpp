class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int slow =nums[0];
       int fast = nums[0];
       while(true){
        slow = nums[slow];
        fast = nums[nums[fast]];
        if(fast == slow){
            break;
        }
       }
       slow = nums[0];
       if(!(slow ==fast)){
        while(true){
            slow= nums[slow];
            fast= nums[fast];
            if(slow == fast){
                break;
            }
        }
       }
       return slow;
    }
};
