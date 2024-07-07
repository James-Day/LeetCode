/*Smarter way to do pre comp

for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pre[i][j] = (grid[i][j] == ch);
                if(i>0) pre[i][j] += pre[i-1][j];
                if(j>0) pre[i][j] += pre[i][j-1];
                if(i>0 && j>0) pre[i][j] -= pre[i-1][j-1];
        }
    }
*/

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        vector<vector<int>> prefixX(grid.size(),
            vector<int>(grid[0].size(), 0));
        vector<vector<int>> prefixY(grid.size(),
            vector<int>(grid[0].size(), 0));

        for (int i = 0; i < grid.size(); i++) {
            int leftX = 0;
            int leftY = 0;
            for (int j = 0; j < grid[i].size(); j++) {
                if (i > 0) {
                    prefixX[i][j] += prefixX[i - 1][j];
                    prefixY[i][j] += prefixY[i - 1][j];
                }
                if (j > 0) {
                    prefixX[i][j] += leftX;
                    prefixY[i][j] += leftY;
                }
                leftX += grid[i][j] == 'X';
                leftY += grid[i][j] == 'Y';
                prefixX[i][j] += grid[i][j] == 'X';
                prefixY[i][j] += grid[i][j] == 'Y';
            }
        }

        int ans = 0;
        for (int i = 0; i < prefixX.size(); i++) {
            for (int j = 0; j < prefixX[0].size(); j++) {
                if (prefixX[i][j] == prefixY[i][j] && prefixX[i][j] > 0) {
                    ans++;
                };
            }
        }


        return ans;
    }
};