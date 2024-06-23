class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minHorizontal = INT_MAX;
        int maxHorizontal = 0;
        int minDown = INT_MAX;
        int maxDown = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    if (i < minDown) minDown = i;
                    if (j < minHorizontal) minHorizontal = j;

                    if (j > maxHorizontal) maxHorizontal = j;
                    if (i > maxDown) maxDown = i;
                }
            }
        }
        return (maxHorizontal - minHorizontal + 1) * (maxDown - minDown + 1);
    }
};