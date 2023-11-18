#include <vector>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> stack; //first = index, second = height

        int largestArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            int newIndex = i;
            while (!stack.empty() && stack.back().second > heights[i]) {
                int curArea = stack.back().second * (i - stack.back().first);
                largestArea = max(largestArea, curArea);
                newIndex = stack.back().first;
                stack.pop_back();
            }
            stack.push_back({ newIndex, heights[i] });
        }

        while (!stack.empty()) {
            int curArea = stack.back().second * (heights.size() - stack.back().first);
            largestArea = max(largestArea, curArea);
            stack.pop_back();
        }
        return largestArea;
    }
};