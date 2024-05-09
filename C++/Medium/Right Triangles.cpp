class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        vector<int> rowOnes(grid.size());
        vector<int> colOnes(grid[0].size());
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    rowOnes[i]++;
                    colOnes[j]++;
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    ans += (rowOnes[i] - 1) * (colOnes[j] - 1);
                }
            }
        }
        return ans;
    }
};