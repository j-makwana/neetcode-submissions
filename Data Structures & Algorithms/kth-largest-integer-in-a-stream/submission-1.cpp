class KthLargest {
   private:
    int k;
    vector<int> nums;

   public:
    KthLargest(int k, vector<int>& nums) {
        this->nums = nums;
        this->k = k;
        make_heap(this->nums.begin(), this->nums.end(), greater<int>());
        while(this->nums.size() > k){
             pop_heap(this->nums.begin(), this->nums.end(), greater<int>());
            this->nums.pop_back();

        }

        
    }

    int add(int val) {
        if (nums.size() < (k)) {
            /// add to heap
            nums.push_back(val);
            push_heap(nums.begin(), nums.end(), greater<int>());
        } else {
            int on_top = nums.front();
            if (val >= on_top) {
                pop_heap(nums.begin(), nums.end(), greater<int>());
                nums.pop_back();
                nums.push_back(val);
                push_heap(nums.begin(), nums.end(), greater<int>());
            }
        }
        return nums.front();
    }
};
