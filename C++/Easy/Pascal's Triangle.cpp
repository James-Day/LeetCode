#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> Pascal;

        for (int i = 0; i <= rowIndex; i++) {
            vector<int> start;
            start.push_back(1);
            for (int j = 0; j < i - 1; j++) {
                start.push_back(Pascal[i - 1][j] + Pascal[i - 1][j + 1]);
            }
            if (rowIndex == 0) {
                return start;
            }
            start.push_back(1);
            Pascal.push_back(start);

        }
        return Pascal[rowIndex];
    }
};