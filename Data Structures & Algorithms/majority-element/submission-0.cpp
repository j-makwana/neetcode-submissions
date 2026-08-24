class Solution {
public:
    int majorityElement(vector<int>& nums) {
       unordered_map<int, int> myMap;
       for(int values: nums){
        myMap[values]++;
       };
    vector<pair<int, int>> myvec;
       for(auto i: myMap){
            myvec.push_back(i);
       }
       sort(myvec.begin(), myvec.end(), comparator);


    return myvec[0].first;

    }

    static bool comparator(const pair<int,int> &p1, const pair<int, int> &p2){
    return p1.second > p2.second;
    }
};