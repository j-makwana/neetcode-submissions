class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector <int>> result;
        unordered_map<int,int> twosum;
        sort(nums.begin(), nums.end());
        for(int i =0; i< nums.size();i++){
            int first = nums[i];
            if(i!=0 && first==nums[i-1]){
                continue;
            }
            int target = 0 - first;
            twosum.clear();
            for(int j=i+1; j<nums.size(); j++){
                if(twosum.contains(target - nums[j])){
                    result.push_back({first,nums[j],target - nums[j]});
                    while(j+1<nums.size() && nums[j]== nums[j+1]){
                        j++;
                    }
                    continue;
                }
                twosum[nums[j]]=1;
            }

        }
        return result;
    }
};
