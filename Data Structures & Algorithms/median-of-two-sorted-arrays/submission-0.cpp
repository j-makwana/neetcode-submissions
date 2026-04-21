class Solution {
public:
    int partitionFound(int l1, int l2, int r1, int r2){
        if(l2 > r1){
            ///we want more from leftarray
            //wer wanna do left = mid +1
            return 0;
        }
        if(l1 > r2){
            // we want less from leftArray so do right = mid;
            //right most insertion point
            return 1;
        }
        return 2; //match found
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //need to choose the right partition
        int l1, l2 = 0;
        int r1, r2 = 0;
        //choose the smaller of the 2 arrays and init  left and right pointer
        vector<int>& leftArray = (nums1.size() <= nums2.size()) ? nums1 : nums2;
        vector<int>& rightArray = (nums1.size() <= nums2.size()) ? nums2 : nums1;

        ///now start left and right pointer on the left array
        int left = 0;
        int right = leftArray.size();
        int leftneeded = (leftArray.size() + rightArray.size() + 1) / 2;
        while(left <= right){
            //if partition found exit!
            int partitionX = left + (right - left) / 2;
            int partitionY = leftneeded - partitionX;
            l1 = partitionX == 0 ? INT_MIN : leftArray[partitionX-1];
            r1 = partitionX == leftArray.size() ? INT_MAX : leftArray[partitionX];
            l2 = partitionY == 0 ? INT_MIN : rightArray[partitionY-1];
            r2 = partitionY == rightArray.size() ? INT_MAX : rightArray[partitionY];
            
            int status = partitionFound(l1, l2, r1, r2);
            if(status == 2){
                //we found the right one
                break;
            } else if(status == 1){
                right = partitionX - 1;
            } else {
                left = partitionX + 1;
            }
        }

        if((leftArray.size() + rightArray.size()) % 2 == 0){
            return (max(l1, l2) + min(r1, r2)) / 2.0;
        } else {
            return max(l1, l2);
        }
    }
};