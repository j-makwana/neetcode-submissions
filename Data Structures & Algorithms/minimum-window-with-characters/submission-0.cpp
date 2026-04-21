class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()> s.size()) return "";
        int need=0;
        int have = 0;
        unordered_map<char,int> char_freq_t;
        unordered_map<char, int> window;
        for(int i = 0; i< t.size();i++){
            char_freq_t[t[i]]++;
            
        }
        need = char_freq_t.size();
        
        int left =0;
        int min_substring = INT_MAX;
        int min_left = 0;
        for(int right = 0; right<s.size(); right++){
            window[s[right]]++;

            if(char_freq_t.contains(s[right]) && window[s[right]]== char_freq_t[s[right]]){
                have++;
            }

              
                while(have==need){
                      if(right - left+1< min_substring){
                    min_substring = right - left +1;
                    min_left = left;
                };
                    window[s[left]]--;

                    if(char_freq_t.contains(s[left]) && window[s[left]]<char_freq_t[s[left]]){
                        have--;
                        
                    }
                    left++;

                }

            

        }
        cout<< min_substring <<endl;
        if(min_substring == INT_MAX) return "";
        return s.substr(min_left, min_substring);
    }
};
