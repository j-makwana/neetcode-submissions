class Solution {
public:


    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> partitionX = (nums1.size() <= nums2.size()) ? nums1:nums2;
        vector<int> partitionY = (nums1.size() > nums2.size()) ?  nums1: nums2;
        //i have the partitions ready
        int left = 0;
        int right = partitionX.size();
        int totalNeeded = (partitionX.size() + partitionY.size() + 1) /2;
        while(left<=right){
            int partition = left + (right - left) /2;
            //number of elements needed from left = partition

            int l1 = (partition==0) ? INT_MIN : partitionX[partition-1];  
            int l2 = (totalNeeded-partition) == 0? INT_MIN: partitionY[totalNeeded-partition-1];
            int r1 = (partition == partitionX.size())? INT_MAX: partitionX[partition];
            int r2 = (totalNeeded-partition == partitionY.size())? INT_MAX: partitionY[totalNeeded-partition];
            if(l2<=r1 && l1<=r2){
                if((partitionX.size() + partitionY.size())%2==0){
                    return (max(l1,l2) + min(r1,r2) )/ 2.0;
                }else{
                    return max(l1,l2);
                }
            }
            if(l1>r2){
                //take less from leftartray
                right = partition-1;
              
            }
            if(l2>r1){
                //take more from left
                left = partition+1;
            }
        }
        return 0;
    }    
};