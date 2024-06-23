class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        std::vector<long long> ret = { nums[0], LLONG_MIN };

        for (int i = 1; i < nums.size(); ++i) {
            long long a = max(ret[0], ret[1]) + nums[i];
            long long b = ret[0] - nums[i];
            ret = { a, b };
        }

        return max(ret[0], ret[1]);
    }
};