class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       int size = cost.size() ;
       if(size == 1){
        return cost[0];
       }
       if(size == 2){
        return min(cost[0], cost[1]);
       }
       int a = cost[0];
       int b = cost[1];

       for(int i=2;i< size;i++){
        int cos = cost[i];
        int final = min(a+cos, b+cos);
        a=b;
        b= final;
       }
       return min(a,b);
    }
};
