class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> myStack;
        for(string ch: tokens){
            if(ch != "+" && ch != "*" && ch != "-" && ch != "/"){
                myStack.push_back(stoi(ch));
            }else{
                int top1 = myStack.back();
                myStack.pop_back();
                int top2 = myStack.back();
                myStack.pop_back();
                if(ch == "+") myStack.push_back(top1 +top2);
                else if(ch == "-") myStack.push_back(top2 -top1);
                else if(ch == "*") myStack.push_back(top2 *top1);
                else if(ch == "/") myStack.push_back(top2 /top1);
                

            }
            
        }
        return myStack.back();
        
    }
};
