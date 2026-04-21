class Solution {
public:
    int search(vector<int>& nums, int target) {
        ///find the minimum
        int left = 0;
        int right = nums.size() -1;
        while(left<right){
            int mid = left + (right - left) / 2;
            if(nums[mid]== target) return mid;
            if(nums[mid]>= nums[left]){
                //we are in the left sorted area
                //check the left point
                if(target >= nums[left] && target <= nums[mid]){
                    //we search hear bro
                    right = mid;
                }else{
                    left = mid+1;
                }
            }else{
                // we are in the right sorted array
                 if(target <= nums[right] && target >= nums[mid]){
                    //we search hear bro
                    left = mid;
                }else{
                    right = mid -1;
                }
            }
        }
        if(nums[left]!= target) return -1;
        return left;
    }  
};
