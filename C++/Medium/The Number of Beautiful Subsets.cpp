class Solution {
public:
    int m_k;
    int beautifulSubsets(vector<int>& nums, int k) {
        m_k = k;
        unordered_map<int, int> seen;
        return dfs(nums, 0, seen) - 1;
    }

    int dfs(vector<int>& nums, int i, unordered_map<int, int>& seen) {
        if (i == nums.size()) {
            return 1;
        }
        int ans = 0;

        if (!seen[nums[i] + m_k] && !seen[nums[i] - m_k]) {
            seen[nums[i]]++;
            ans += dfs(nums, i + 1, seen);
            seen[nums[i]]--;
        }
        ans += dfs(nums, i + 1, seen);
        return ans;
    }

};