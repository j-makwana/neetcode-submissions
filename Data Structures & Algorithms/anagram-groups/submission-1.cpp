class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hp;
        for(string& s: strs){
            string key = s;
            sort(key.begin(), key.end());
            hp[key].push_back(s);
            
        }
        vector<vector<string>> result;
        for(auto& [key,value]: hp){
            result.push_back(value);
        }
        return result;
    }
};
