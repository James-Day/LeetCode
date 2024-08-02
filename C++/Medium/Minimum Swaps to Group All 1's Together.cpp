class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) ones++;
        }
        int l = 0;
        int window_ones = 0;
        int max_window_ones = 0;
        for (int r = 0; r < 2 * nums.size(); r++) {
            if (nums[r % nums.size()] == 1) window_ones++;
            if (r - l >= ones) {
                if (nums[l % nums.size()] == 1) window_ones--;
                l++;
            }
            max_window_ones = max(max_window_ones, window_ones);
        }
        return ones - max_window_ones;
    }
};