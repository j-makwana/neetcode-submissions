class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 1){
            return nums[0];
        }
        if(size ==2){
            return max(nums[0],nums[1]);
        }
        ////remove first element.
        int a = nums[1];
        int b = nums[2];
        for(int i = 3;i< size;i++){
            int result = max(a,b);
            b= nums[i]+a;
            a = result;

        }
        int final1 = max(a,b);

        int c = nums[0];
        int d = nums[1];
        for(int j =2; j<size-1;j++){
            int res = max(c,d);
            d = nums[j]+c;
            c = res;
        }
        int final2= max(d,c);
        return max(final1,final2);
        
        
    }
};
