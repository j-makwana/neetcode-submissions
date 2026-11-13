class Solution {
public:
    int countSubstrings(string s) {
       int ans = 0;
       for(int i =0;i<s.size();i++) {
        int count_odd = countPalindromes(s,i,i);
        int count_even = countPalindromes(s,i,i+1);
        ans += (count_odd + count_even);
       }
       return ans;
    }
    int countPalindromes(string s, int left, int right){
        int count = 0;
        while(left>=0 && right <s.size() && s[left]==s[right]){
            count++;
            left--;
            right++;

        }
        return count;
    }
};
