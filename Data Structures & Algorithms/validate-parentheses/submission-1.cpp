class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> pairs = {
            {'{', '}'},
            {'[', ']'},
            {'(', ')'}
        };
        vector<char> mystack;
        for(char w: s){
            if(w=='{' || w== '(' || w=='['){
                mystack.push_back(w);
            }else{
                if(!mystack.empty()){
                    char atback = mystack.back();
                    mystack.pop_back();
                    if(pairs[atback]!= w){
                        return false;
                    }


                }else{
                    return false;
                }
            }
        }
        if(mystack.empty()){
            return true;
        }
        return false;
    }
};
