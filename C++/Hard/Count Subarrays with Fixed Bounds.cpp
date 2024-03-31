// Sliding window, O(N) Time, O(1) Space.
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int l = 0;
        int curMin = INT_MAX, curMax = INT_MIN;
        int minIndex = 0, maxIndex = 0;
        for (int r = 0; r < nums.size(); r++) {
            curMin = min(curMin, nums[r]);
            curMax = max(curMax, nums[r]);
            if (curMin < minK || curMax > maxK) {
                l = r + 1;
                curMin = INT_MAX;
                curMax = INT_MIN;
            }
            if (nums[r] == minK) minIndex = r;
            if (nums[r] == maxK) maxIndex = r;
            if (curMin == minK && curMax == maxK) {
                ans += min(minIndex, maxIndex) - l + 1;
            }
        }
        return ans;
    }
};