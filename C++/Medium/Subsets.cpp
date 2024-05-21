class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curSub;
        dfs(res, nums, 0, curSub);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& nums, int i, vector<int>& cur) { //cur means cur subset
        if (i >= nums.size()) {
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[i]);
        dfs(res, nums, i + 1, cur);
        cur.pop_back();
        dfs(res, nums, i + 1, cur);
    }
};

/* iterative solution (this was what I initially came up with but I wanted to learn backtracking)
class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        for(int num: nums){
            int size = res.size();
            for(int i = 0; i < size; i++){
                res.push_back(res[i]);
                res.back().push_back(num);
            }
        }
        return res;
    }
};
*/