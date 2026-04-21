class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int containsZero = 0;
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> postfix(n);
        vector<int> result(n);
        prefix[0]=1;
        postfix[n-1] = 1;
        for(int i=1; i< n; i++){
            prefix[i] = prefix[i-1]*nums[i-1];

        }
        for(int j=n-2; j>=0; j--){
            postfix[j] = postfix[j+1]*nums[j+1];

        }
        for(int i=0; i< n;i++){
            result[i] = prefix[i]*postfix[i];
        }
        return result;

    }
};
