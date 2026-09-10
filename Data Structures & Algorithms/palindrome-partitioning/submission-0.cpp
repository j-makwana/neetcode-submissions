class Solution {
public:
    vector<vector<string>> partition(string s) {
       vector<vector<string>> ans;
       vector<string> temp;
       backtrack(s, ans, temp);
       return ans; 
    }
    bool isPalindrome(string word){
        int left = 0;
        int right = word.size()-1;
        while(left < right){
           if(word[left]!=word[right]){
            return false;

           } 
           left++;
           right --;
        }
        return true;
    }
    void backtrack(string curr, vector<vector<string>>&ans, vector<string> & temp){
        if(curr.size()==0){
            ans.push_back(temp);
            return;
        } 
        for(int i =0 ;i<curr.size();i++){
            string part = curr.substr(0,i+1);
            if(isPalindrome(part)){
                temp.push_back(part);
                backtrack(curr.substr(i+1), ans, temp);
                temp.pop_back();
            }
        }
        

    }
};
