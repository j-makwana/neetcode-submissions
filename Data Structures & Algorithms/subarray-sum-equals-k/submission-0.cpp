class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int n = nums.size();
      vector<int> prefixSum(n+1);
      unordered_map<int,int> myMap;
     myMap[0]=1;
     int res =0;
      for(int i = 0; i<n; i++){
        int newValue = nums[i]+ prefixSum[i];
        if(myMap.contains(newValue-k)){
            res += myMap[newValue-k];

        }
        prefixSum[i+1]= newValue;
        myMap[newValue]++;
       
      }
      return res;
    }
};