class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        int l = 0;
        unordered_map<int, int> count;
        for (int r = 0; r < nums.size(); r++) {
            while (count[nums[r]] == k) {
                count[nums[l]]--;
                l++;
            }
            count[nums[r]]++;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};