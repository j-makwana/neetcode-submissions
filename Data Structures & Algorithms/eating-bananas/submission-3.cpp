class Solution {
public:
    bool calculate(vector<int>& piles_sorted, int mid, int h){
        int val = 0;
        for(int n: piles_sorted){
            if(n < mid){
                val+= 1;
            }else{
                val+= (n+mid -1)/mid;
            }
        }
        if(val>h) return false;
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int left = 1;
        int right = piles[piles.size()-1];
        while(left < right){
            int mid = left + (right - left) / 2;
            if(calculate(piles, mid, h)){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};
