class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(),0);
        vector<int> mystack;//indexes here
        for(int i =0; i<temperatures.size(); i++){
            int current = temperatures[i];
            if(!mystack.empty() && temperatures[mystack.back()]< current){
                while(!mystack.empty() && temperatures[mystack.back()] < current){
                    result[mystack.back()]= (i-mystack.back());
                    mystack.pop_back();
                }

            }
         
            mystack.push_back(i);


        }
        return result;
    }
};
