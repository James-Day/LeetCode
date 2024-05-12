//itterative solution (supprisngly only a tiny bit better than my DP solution.)
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans = INT_MIN;
       //add energy backwards.
        for (int j = energy.size() - k - 1; j >= 0; j--) {
            energy[j] += energy[j + k];
        }
        for (int i = 0; i < energy.size(); i++) {
            ans = max(ans, energy[i]);
        }
        return ans;
    }
};

//initial solution, top down, but there is a better approach above
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> dp(energy.size(), 0);
        int maxEnergy = -INT_MAX;
        for (int i = 0; i < energy.size(); i++) {
            maxEnergy = max(maxEnergy, dfs(i, k, energy, dp));
        }
        return maxEnergy;
    }
    int dfs(int i, int k, vector<int>& energy, vector<int>& dp) {
        if (i >= energy.size()) return 0;
        if (dp[i] != 0) return dp[i];
        int ans = dfs(i + k, k, energy, dp);
        ans += energy[i];
        dp[i] = ans;
        return ans;
    }
};