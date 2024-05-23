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

//O(n)
class Solution {
public:
    unordered_map<int, int> cache;
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> masterCount;
        for (int num : nums) {
            masterCount[num]++;
        }
        vector<unordered_map<int, int>> groups;
        unordered_set<int> visited;
        for (auto i = masterCount.begin(); i != masterCount.end(); i++) {
            if (visited.contains(i->first)) continue; //visited this key already.

            unordered_map<int, int> g;
            int n = i->first;
            while (masterCount.contains(n - k)) {
                n -= k; //could optimize this a tiny bit
            }
            //n is the minimum value
            while (masterCount.contains(n)) {
                g[n] = masterCount[n];
                visited.insert(n);
                n += k;
            }
            groups.push_back(g);
        }
        int res = 1;
        for (unordered_map<int, int>& g : groups) {
            int minimumKey = INT_MAX;
            for (auto i = g.begin(); i != g.end(); i++) {
                minimumKey = min(minimumKey, i->first);
            }
            res *= helper(minimumKey, g, masterCount, k);
        }
        return res - 1;

    }
    int helper(int n, unordered_map<int, int>& g, unordered_map<int, int> count, int& k) {
        if (!g.contains(n))
            return 1;
        if (cache.contains(n)) return cache[n]; //a number can only be in one group so we don't have to worry about the group changing.
        int skip = helper(n + k, g, count, k);
        int include = (pow(2, g[n]) - 1) * helper(n + (2 * k), g, count, k); //you have to skip the next k value because you can't do 2 in a row
        cache[n] = skip + include;
        return skip + include;
    }
};