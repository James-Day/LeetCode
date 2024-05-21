class Solution { //there are better solutions using bit shifting, but it's not something I'm confident on yet
public:
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets = { {} };
        for (int num : nums) {
            int size = subsets.size();
            for (int i = 0; i < size; i++) {
                subsets.push_back(subsets[i]);
                subsets.back().push_back(num);
            }
        }
        int sum = 0;

        for (vector<int>& subset : subsets) {
            int xorTotal = 0;
            for (int& num : subset) {
                xorTotal ^= num;
            }
            sum += xorTotal;
        }
        return sum;
    }
};

// Better memory.
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int total = 0;
        return dfs(0, total, nums);
    }
    int dfs(int i, int total, vector<int>& nums) {
        if (i == nums.size()) return total;
        return dfs(i + 1, total ^ nums[i], nums) + dfs(i + 1, total, nums);
    }
};