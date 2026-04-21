class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //store key: value (numbers[i], i)
        unordered_map<int, int> hp;
        for(int i=0;i<numbers.size(); i++){
            if(hp.contains(target-numbers[i])){
                return {hp[target-numbers[i]]+1, i+1};
            }
            hp[numbers[i]]= i;
        }
    }
};
