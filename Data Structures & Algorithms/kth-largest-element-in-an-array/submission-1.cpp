class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int,vector<int>, greater<int>> min_heap;
       
       for(int value: nums) {
        if(min_heap.size()==k && min_heap.top()> value){
            continue;
        }
        if(min_heap.size()==k && (min_heap.top()<=value)){
            min_heap.pop();
                

        }
        min_heap.push(value);
       }
       return min_heap.top();
    }
};
