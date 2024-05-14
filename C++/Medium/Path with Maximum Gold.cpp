class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxGold = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                maxGold = max(maxGold, dfs(i, j, grid));
            }
        }
        return maxGold;
    }
    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == 0) {
            return 0;
        }

        int bestDirectionGold = 0;
        int copy = grid[i][j];
        grid[i][j] = 0;
        bestDirectionGold = max(bestDirectionGold, dfs(i + 1, j, grid));
        bestDirectionGold = max(bestDirectionGold, dfs(i - 1, j, grid));
        bestDirectionGold = max(bestDirectionGold, dfs(i, j + 1, grid));
        bestDirectionGold = max(bestDirectionGold, dfs(i, j - 1, grid));
        grid[i][j] = copy;
        return bestDirectionGold + copy;
    }
};

// The solution below is 3 times faster with the given test cases!
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxGold = 0;
        int total = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                total += grid[i][j];
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (maxGold == total) return total;
                maxGold = max(maxGold, dfs(i, j, grid));
            }
        }
        return maxGold;
    }
    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == 0) {
            return 0;
        }

        int bestDirectionGold = 0;
        int copy = grid[i][j];
        grid[i][j] = 0;
        bestDirectionGold = max(bestDirectionGold, dfs(i + 1, j, grid));
        bestDirectionGold = max(bestDirectionGold, dfs(i - 1, j, grid));
        bestDirectionGold = max(bestDirectionGold, dfs(i, j + 1, grid));
        bestDirectionGold = max(bestDirectionGold, dfs(i, j - 1, grid));
        grid[i][j] = copy;
        return bestDirectionGold + copy;
    }
};