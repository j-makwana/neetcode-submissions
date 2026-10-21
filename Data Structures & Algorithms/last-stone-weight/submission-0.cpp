class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       if(stones.size()==1){
        return stones[0];
       } 
       make_heap(stones.begin(), stones.end());
       while(stones.size()>1){
        int first = stones.front();
        pop_heap(stones.begin(), stones.end());
        stones.pop_back();
        int second = stones.front();

        pop_heap(stones.begin(), stones.end());
        stones.pop_back();
        if(first>second){
            int third = first - second;
            stones.push_back(third);
            push_heap(stones.begin(), stones.end());

        }

       }
       if(!stones.empty()){
        return stones[0];
       }
        return 0;
    }
};
