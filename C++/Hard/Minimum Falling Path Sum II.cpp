/*
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int minimum = INT_MAX;
        for(int i = 0; i < grid[0].size(); i++){
            minimum = min(minimum, helper(0, i, grid));
        }
        return minimum;
    }
    int helper(int i, int j, vector<vector<int>>& grid){
        if(i == grid.size() - 1){
            return grid[i][j];
        }
        int minimum = INT_MAX;
        for(int k = 0; k < grid[i].size(); k++){
            if(k == j) continue;
            minimum = min(minimum, helper(i + 1, k , grid));
            cout << minimum << endl;
        }
        return minimum + grid[i][j];
    }
};
*/
/* add DP / memoization
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int minimum = INT_MAX;
        map<pair<int,int>,int> map;
        for(int i = 0; i < grid[0].size(); i++){
            minimum = min(minimum, helper(0, i, grid, map));
        }
        return minimum;
    }
    int helper(int i, int j, vector<vector<int>>& grid, map<pair<int,int>, int>& map){
        if(map.contains({i,j})){
            return map[{i,j}];
        }
        if(i == grid.size() - 1){
            return grid[i][j];
        }
        int minimum = INT_MAX;
        for(int k = 0; k < grid[i].size(); k++){
            if(k == j) continue;
            minimum = min(minimum, helper(i + 1, k , grid, map));
            cout << minimum << endl;
        }
        map[{i,j}] = minimum + grid[i][j];
        return minimum + grid[i][j];
    }
};
*/

//Final solution using 2D array (although it does sound like there is a slightly better solution, I may learn it later, and add it here.)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int minimum = INT_MAX;
        int dp[201][201];
        for (int i = 0; i < 201; i++) {
            for (int j = 0; j < 201; j++) {
                dp[i][j] = -1;
            }
        }
        for (int i = 0; i < grid[0].size(); i++) {
            minimum = min(minimum, helper(0, i, grid, dp));
        }
        return minimum;
    }
    int helper(int i, int j, vector<vector<int>>& grid, int map[201][201]) {
        if (map[i][j] != -1) {
            return map[i][j];
        }
        if (i == grid.size() - 1) {
            return grid[i][j];
        }
        int minimum = INT_MAX;
        for (int k = 0; k < grid[i].size(); k++) {
            if (k == j) continue;
            minimum = min(minimum, helper(i + 1, k, grid, map));
        }
        map[i][j] = minimum + grid[i][j];
        return minimum + grid[i][j];
    }
};