class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        long long res = nums[0], cur = 0, prev = 0;
        for (int i = 1; i < nums.size(); ++i) {
            res += nums[i];
            if (nums[i] >= 0) {
                res += 2 * max(cur, prev);
                cur = prev = 0;
            }
            else {
                long long temp = cur;
                cur = prev - nums[i];
                prev = max(temp, prev);
            }
        }
        return res + 2 * max(cur, prev);
    }
};