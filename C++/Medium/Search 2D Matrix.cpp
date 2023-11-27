#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int up = 0;
        int down = matrix.size() - 1;

        while (up <= down) {
            int mid = (up + down) / 2;
            int endOfRow = matrix[mid].size() - 1;
            if (target > matrix[mid][endOfRow]) {
                up = mid + 1;
            }
            else if (target < matrix[mid][0]) {
                down = mid - 1;
            }
            else break;// must be in this row, otherwise it doesn't exist.
        }
        if (up > down) return false;

        int l = 0;
        int r = matrix[0].size() - 1;
        int mid = (up + down) / 2;
        while (l <= r) {
            int midRow = (l + r) / 2;
            if (matrix[mid][midRow] == target) {
                return true;
            }
            if (target > matrix[mid][midRow]) {
                l = midRow + 1;
            }
            else {
                r = midRow - 1;
            }
        }
        return false;
    }
};