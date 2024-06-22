class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int curTotal = 0;
        int ans = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            curTotal += nums[i] % 2;
            if (map.contains(curTotal - k)) {
                ans += map[curTotal - k];
            }
            map[curTotal]++;
        }
        return ans;
    }
};