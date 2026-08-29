class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       vector<int> result;
       unordered_map<int, int> temp;
        int threshold = nums.size()/3;
        int n = nums.size();
        for(int i =0; i< n; i++){
           if(temp[nums[i]]!=-1){
            temp[nums[i]]++;
           } 
            if(temp[nums[i]]>threshold){
                cout << nums[i] <<endl;
                result.push_back(nums[i]);
                temp[nums[i]]= -1;
            }}
        return result;

    }
};