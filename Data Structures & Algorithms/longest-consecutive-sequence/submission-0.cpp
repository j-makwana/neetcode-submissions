class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longestConsecutive = 0;
        unordered_set<int> numSet(nums.begin(), nums.end());
        for(int n: nums){
           if(numSet.find(n-1)==numSet.end()){
            //start from here
            int currentN = n;
            int tempLength = 1;
            while(numSet.find(currentN+1)!= numSet.end()){
                tempLength += 1;
                currentN++;
            }
            longestConsecutive = max(tempLength, longestConsecutive);
           }


        }
        return longestConsecutive;
        
    }
};
