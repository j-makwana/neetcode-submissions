class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        };

        unordered_map<char, int> hp;
        for(int i=0; i<s.size();i++){
            hp[s[i]]++;
            hp[t[i]]--;
        }
        for(auto& pair: hp){
            if(pair.second!=0){
                return false;
            }
        }
        return true;

        
    }
       
};
