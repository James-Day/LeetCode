class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 1; i < grid.size() - 1; i++) {
            for (int j = 1; j < grid[i].size() - 1; j++) {
                int sum = grid[i][j - 1] + grid[i][j] + grid[i][j + 1];
                //horizontal
                if (grid[i - 1][j] + grid[i - 1][j + 1] + grid[i - 1][j + 2] != sum) continue;
                if (grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2] != sum) continue;

                //vertical
                if (grid[i - 1][j - 1] + grid[i][j - 1] + grid[i + 1][j - 1] != sum) continue;
                if (grid[i - 1][j] + grid[i][j] + grid[i + 1][j] != sum) continue;
                if (grid[i - 1][j + 1] + grid[i][j + 1] + grid[i + 1][j + 1] != sum) continue;

                //diagonal
                if (grid[i - 1][j - 1] + grid[i][j] + grid[i + 1][j + 1] != sum) continue;
                if (grid[i + 1][j - 1] + grid[i][j] + grid[i - 1][j + 1] != sum) continue;
                ans++;
            }
        }
        return ans;
    }
};