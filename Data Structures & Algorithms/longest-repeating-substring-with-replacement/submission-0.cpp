class Solution {
private:
    int alphabets[26]= {0};

public:
    int getMostFrequent(){
        int max_int= 0;
        for(int i = 0; i< 26; i++){
            max_int = max(alphabets[i], max_int);
        }
        return max_int;
    }
    int characterReplacement(string s, int k) {
        if(s.size()<2){
            return 1;
        }
        int left = 0;
        int longest_substring=0;
        
        for(int right = 0; right < s.size(); right++){
            //window  validcondition:
            //right - left + 1 - (most frequent count) <=k
            alphabets[s[right]- 'A']++;

            while(right - left+1 - getMostFrequent()>k){
                alphabets[s[left]- 'A']--;
                left++;
            }
            longest_substring   = max(longest_substring, right - left +1);
        }

        return longest_substring;
    }
};
