class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    floodFill(i, j, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
    void floodFill(int i, int j, vector<vector<char>>& grid) {
        if (i >= grid.size() || i < 0 || j < 0 || j >= grid[i].size()) return; //boundary check
        if (grid[i][j] != '1') return;
        grid[i][j] = 'v'; //for visited

        floodFill(i + 1, j, grid);
        floodFill(i - 1, j, grid);
        floodFill(i, j + 1, grid);
        floodFill(i, j - 1, grid);
    }
};