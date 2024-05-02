//O(N) TC , O(N) SC (you could also do O(NlogN) TC and O(1) SC by using binary search on each number.)
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            seen.insert(num);
        }
        int ans = 0;
        for (int num : nums) {
            if (seen.contains(-num)) {
                ans = max(ans, num);
            }
        }
        return ans == 0 ? -1 : ans;
    }
};