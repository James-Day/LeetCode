class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int res = rows * (1 << (cols - 1)); //all the MSB's
        for (int i = 1; i < cols; i++) {
            int count = 0;
            for (int j = 0; j < rows; j++) {
                if (grid[j][i] != grid[j][0]) {
                    count++;
                }
            }
            count = max(count, rows - count); //majority 1's or majority 0's
            res += count * (1 << cols - i - 1);
        }
        return res;
    }
};
/* original solution by editing array.
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        for(vector<int>& row : grid){
            if(row[0] == 0){
                for(int i = 0; i < row.size(); i++){
                   // row[i] = (row[i] == 0) ? 1 : 0;
                    row[i] = (row[i] + 1) % 2;
                }
            }
        }

        for(int i = cols - 1; i >= 0; i--){
            int zeros = 0;
            for(int j = 0; j < rows; j++){
                zeros += (grid[j][i] == 0);
            }
            if(zeros > rows / 2){
                for(int j = 0; j < rows; j++){
                    grid[j][i] = (grid[j][i] == 0) ? 1 : 0;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    ans += pow(2, cols - j - 1);
                }
            }
        }
        return ans;


    }
};
*/