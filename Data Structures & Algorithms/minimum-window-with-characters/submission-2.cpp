class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()> s.size()) return "";
        unordered_map<char, int> s_count;
        unordered_map<char, int> t_count;
        int need = 0;
        int have = 0;
        int left = 0;
        int min_substr = INT_MAX;
        for(char n: t){
            t_count[n]++;
        }
        need = t_count.size();
        int min_left = 0;
        int min_right= 0;
        for(int right = 0; right< s.size(); right++){
            s_count[s[right]]++;
            if(t_count.contains(s[right]) && s_count[s[right]]== t_count[s[right]]){
                have ++;
                cout << "reached here" << endl;
            }
            while(have == need){
                if(right - left+1 < min_substr){
                    min_left = left;
                    min_right = right;
                    min_substr = right - left +1;
                }
                if(s_count[s[left]] == t_count[s[left]]){
                    
                    have --;

                }
                s_count[s[left]]--;
                left++;
            }
        }
        if (min_substr == INT_MAX) return "";
        return s.substr(min_left, min_right - min_left +1);
        
    }
};
