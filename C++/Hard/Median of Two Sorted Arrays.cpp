class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }


        int totalSize = nums1.size() + nums2.size();
        double result = 0.0;
        int low = 0;
        int high = nums1.size();

        while (low <= high) {
            //nums1
            int i = low + (high - low) / 2;
            //nums2
            int j = ((totalSize + 1) / 2) - i;


            int left1 = (i > 0) ? nums1[i - 1] : INT_MIN; // act like -infinity and positive infinity are on the ends of the arrays.
            int right1 = (i < nums1.size()) ? nums1[i] : INT_MAX;
            int left2 = (j > 0) ? nums2[j - 1] : INT_MIN;
            int right2 = (j < nums2.size()) ? nums2[j] : INT_MAX;

            if (left1 <= right2 && left2 <= right1) { // partition is correct
                if (totalSize % 2 == 0) { //even number of elements
                    result = (max(left1, left2) + min(right1, right2)) / 2.0;
                }
                else { // odd number of elements
                    result = max(left1, left2);
                }
                break;
            }
            else if (left1 > right2) {
                high = i - 1;
            }
            else {
                low = i + 1;
            }
        }

        return result;
    }
};