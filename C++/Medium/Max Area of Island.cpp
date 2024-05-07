class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    res = max(calcArea(grid, i, j), res);
                }
            }
        }
        return res;
    }
    int calcArea(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() ||
            grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 0;
        int areaSoFar = 0;
        areaSoFar += calcArea(grid, i + 1, j);
        areaSoFar += calcArea(grid, i - 1, j);
        areaSoFar += calcArea(grid, i, j + 1);
        areaSoFar += calcArea(grid, i, j - 1);
        return areaSoFar + 1;
    }
};