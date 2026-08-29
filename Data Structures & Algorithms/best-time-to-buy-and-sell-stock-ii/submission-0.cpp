class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i =1; i<prices.size(); i++){
            int a = prices[i-1];
            int b = prices[i];
            if((b-a)>0){
                profit += (b-a);

            }   
        }
        return profit;
        
    }
};