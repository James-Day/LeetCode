#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        int ans = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> prev_heights(cols, 0);

        for (int i = 0; i < rows; i++)
        {

            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 1)
                {
                    prev_heights[j] += 1;
                }
                else
                    prev_heights[j] = 0;
            }
            vector<int> curHeights = prev_heights;
            sort(curHeights.begin(), curHeights.end(), greater<>());

            for (int k = 0; k < curHeights.size(); k++)
            {
                ans = max(ans, curHeights[k] * (k + 1));
            }
        }
        return ans;
    }
};