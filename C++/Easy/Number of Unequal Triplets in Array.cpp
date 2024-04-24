class Solution { //O(n) TC, combinitorics.
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n : nums)
            ++m[n];
        int res = 0, left = 0, right = nums.size();
        for (pair<const int, int>& cur : m) {
            right -= cur.second;
            res += left * cur.second * right;
            left += cur.second;
        }
        return res;
    }
};

/* initial solution just simply iterate over all posibilities. o(n^3)
class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (j == i) continue;
                for (int k = j; k < nums.size(); k++) {
                    if (k == j) continue;
                    if (nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k]) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};*/