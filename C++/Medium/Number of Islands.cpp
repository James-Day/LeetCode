class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] != '1') {
                    continue;
                }
                floodFill(grid, i, j);
                ans++;
            }
        }
        return ans;
    }
    void floodFill(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()) return;
        if (grid[i][j] != '1') return;
        grid[i][j] = 0;
        floodFill(grid, i + 1, j);
        floodFill(grid, i - 1, j);
        floodFill(grid, i, j + 1);
        floodFill(grid, i, j - 1);
    }
};