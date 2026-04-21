class Solution {
public:
    int trap(vector<int>& height) {

        int left = 0;
        int right = height.size()-1;
        int maxLeft= height[left];
        int maxRight = height[right];
        int total =0;
        while(left<right){
            //you do l++ when le
            maxLeft = max(maxLeft, height[left]);
            maxRight = max(maxRight, height[right]);
            ////the way you calcualte area
            int waterstore = 0;
            if(height[left]<height[right]){
                waterstore =  min(maxLeft, maxRight) - height[left];
                left++;
                 

            }else{
                waterstore =  min(maxLeft, maxRight) - height[right];

                right--;

            }
            
            if(waterstore>0){
                total+=waterstore;
            }

        }
        return total;

    
    }
};
