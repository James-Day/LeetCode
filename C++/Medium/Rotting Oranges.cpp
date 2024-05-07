class Solution {
public:
    void addToQueue(int i, int j, queue<pair<int, int>>& q, vector<vector<int>>& grid) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()) return;
        if (grid[i][j] == 1) {
            grid[i][j] = 2;
            q.push({ i,j });
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({ i,j });
                }
            }
        }
        int dist = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) { //come back
                pair<int, int>ij = q.front();
                q.pop();

                addToQueue(ij.first + 1, ij.second, q, grid);
                addToQueue(ij.first - 1, ij.second, q, grid);
                addToQueue(ij.first, ij.second + 1, q, grid);
                addToQueue(ij.first, ij.second - 1, q, grid);
            }
            dist++;
        }
        bool emptyGrid = true;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) return -1;
                if (grid[i][j] == 2) emptyGrid = false;
            }
        }
        return emptyGrid ? 0 : dist - 1;
    }
};