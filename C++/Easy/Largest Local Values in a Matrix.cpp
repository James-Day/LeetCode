// a bit more consice solution
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size() - 2, vector<int>(grid.size() - 2, 0));
        for (int i = 0; i < ans.size(); i++)
            for (int j = 0; j < ans[i].size(); j++)
                for (int k = 0; k < 3; k++)
                    for (int l = 0; l < 3; l++)
                        ans[i][j] = max(ans[i][j], grid[i + k][j + l]);
        return ans;
    }
};

//
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size() - 2, vector<int>(grid.size() - 2, 0));
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                int localMax = -INT_MAX;
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        localMax = max(localMax, grid[i + k][j + l]);
                    }
                }
                ans[i][j] = localMax;
            }
        }
        return ans;
    }
};