class Solution {
public:
    vector<string> letterCombinations(string digits) {
         vector<string> ans;
        if(digits.size()<1){
            return ans;
        }
       unordered_map<int, string> digi = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7,"pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
       };
      
      string args;
      for(auto& val: digits){
        int value = val - '0';
        args+= digi[value];
        cout << args << endl;
      }
      string curr;

      backtrack(curr, ans, digits, 0 , digi);
      
      return ans;
    }
    void backtrack(string curr, vector<string>& ans, string digits, int i, unordered_map<int, string> &digi){
        cout << curr.size() <<endl;
        if(curr.size()== digits.size()){
            ans.push_back(curr);
            return;
        
        }
        for(int j =i; j< digits.size(); j++){
        string a = digi[(digits[j] - '0')];
        for(char ec: a){
            curr.push_back(ec);
            backtrack(curr, ans, digits, j +1, digi);
            curr.pop_back();
            
        }
      }

    }
};
