class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int res = INT_MIN;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                //smallest of above or left.
                int pre = min(i > 0 ? grid[i - 1][j] : INT_MAX, j > 0 ? grid[i][j - 1] : INT_MAX);
                res = max(res, grid[i][j] - pre);
                grid[i][j] = min(grid[i][j], pre);
            }
        }
        return res;
    }
};