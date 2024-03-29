//sliding window O(N) Time O(1) Space
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int maxElement = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxElement) maxElement = nums[i];
        }

        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == maxElement) {
                count++;
            }
            while (count > k || (count == k && nums[l] != maxElement)) {
                if (nums[l] == maxElement) {
                    count--;
                }
                l += 1;
            }
            if (count == k) {
                ans += l + 1;
            }
        }


        return ans;
    }
};