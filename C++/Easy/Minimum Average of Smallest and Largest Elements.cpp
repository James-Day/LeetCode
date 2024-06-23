class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        double minAverage = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            minAverage = min(minAverage, ((double)nums[i] + nums[nums.size() - i - 1]) / 2);
        }
        return minAverage;
    }
};