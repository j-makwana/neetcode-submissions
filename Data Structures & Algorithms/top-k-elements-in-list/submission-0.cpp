class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //k most frequent elements within the array
        unordered_map <int, int> hp;
        for(int& num: nums){
            hp[num]++;
        }
        vector<pair<int,int>> v(hp.begin(), hp.end());
        sort(v.begin(), v.end(), [](auto& a, auto& b){
            return a.second > b.second;
        });
        vector<int> result;
        for(int i=0; i<k;i++){
            result.push_back(v[i].first);
        }
        return result;

    }
};
