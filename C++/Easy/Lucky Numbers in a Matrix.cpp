//Its actually only possible to have one lucky number or 0 lucky numbers, because if a number is a lucky number then another number would have to be less than the first lucky number, and greater than that number as well. (prrof by contradiction QED.)
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> luckyNumbers;

        int maxOfRowMins = INT_MIN;
        for (int i = 0; i < matrix.size(); i++) {
            int curMin = INT_MAX;
            for (int j = 0; j < matrix[i].size(); j++) {
                curMin = min(curMin, matrix[i][j]);
            }
            maxOfRowMins = max(curMin, maxOfRowMins);
        }

        for (int i = 0; i < matrix[0].size(); i++) {
            int curMax = INT_MIN;
            for (int j = 0; j < matrix.size(); j++) {
                if (matrix[j][i] > curMax) {
                    curMax = matrix[j][i];
                }
            }
            if (maxOfRowMins == curMax) luckyNumbers.push_back(curMax);
        }
        return luckyNumbers;
    }
};