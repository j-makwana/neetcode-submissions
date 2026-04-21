class MinStack {
private:
       vector<int> minimums;
       vector<int> values;
public:
    MinStack() {
     
        
    }
    
    void push(int val) {
        values.push_back(val);
        if(minimums.empty()){
            minimums.push_back(val);
        }else{
            int back = minimums.back();
            if(back>=val){
                minimums.push_back(val);
            }
        }
        
    }
    
    void pop() {
        int toRemove = values.back();
        values.pop_back();
        if(toRemove == getMin()){

            minimums.pop_back();
        }
        
        
    }
    
    int top() {
        return values.back();
        
    }
    
    int getMin() {
        return minimums.back();
        
    }
};
