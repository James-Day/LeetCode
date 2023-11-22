#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> diagonal;

        unordered_map<int, vector<int>> diagonalMap;
        int maximum = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                diagonalMap[i + j].push_back(nums[i][j]);
                maximum = max(i + j, maximum);
            }
        }

        for (int i = 0; i <= maximum; i++) {
            reverse(diagonalMap[i].begin(), diagonalMap[i].end()); //might be faster to just use a backwards iterator instead of reversing.
            diagonal.insert(diagonal.end(), diagonalMap[i].begin(), diagonalMap[i].end());
        }

        return diagonal;
    }
};