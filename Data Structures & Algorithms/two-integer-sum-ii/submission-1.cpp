class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //store key: value (numbers[i], i)
        int left = 0;
        int right = numbers.size()-1;
        while(left<right){
            int toCheck = numbers[left] + numbers[right];
            if(toCheck == target){
                return {left+1, right+1};
            }
            if(toCheck< target){
                left++;
            }else{
                            right--;

            }
        }
    }
};
