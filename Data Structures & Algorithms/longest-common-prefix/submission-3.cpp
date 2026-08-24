
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       string prefix = strs[0];

       for(int i =1 ; i< strs.size(); i++){
        string curWord = strs[i];
        //i need to prefix to this
        int j;
        for(j =0; j< prefix.size(); j++){
            if(curWord[0]!=prefix[0]){
                return "";
            }
           if(j>= curWord.size() || prefix[j] != curWord[j]){
            break;
           }
        };
        prefix = prefix.substr(0, j);
       } 
       return prefix;   
       }

};