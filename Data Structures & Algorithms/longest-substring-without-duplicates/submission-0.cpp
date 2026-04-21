class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int longest_substring = 0;
        unordered_set<char> repeatedchar;
        for(int right = 0; right < s.size(); right++){

            if(repeatedchar.contains(s[right])){
                while(repeatedchar.contains(s[right])){
                    repeatedchar.erase(s[left]);
                    left++;

                }


            }
                longest_substring = max(longest_substring, right - left +1);

                repeatedchar.insert(s[right]);
            
        }
        return longest_substring;
    }
};
