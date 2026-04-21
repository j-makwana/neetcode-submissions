class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;//where we store it
        vector<int> ans;
        cout <<k << endl;
        for(int i = 0; i<k;i++){
            while(!dq.empty() && nums[dq.back()]< nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

        }
        int left = 0;
        for(int right = k-1; right< nums.size(); right++){
            while(!dq.empty() && dq.front()< left){
                dq.pop_front();
            }
             while(!dq.empty() && nums[dq.back()]< nums[right]){
                dq.pop_back();
            }
            dq.push_back(right);
            ans.push_back(nums[dq.front()]);
          
            left++;
        }
        
        return ans;

    }
};
