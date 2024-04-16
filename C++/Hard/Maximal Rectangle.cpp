//uses largest rectangle in a histogram algorithm!! (quite easy onces you see this!)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        vector<int> heights(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '0') heights[j] = 0;
                else heights[j] ++; //since it can only be a one.
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>>
            stack; // first = index of how far back it can go, second = height
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            int width = i;
            while (!stack.empty() && heights[i] < stack.top().second) {
                int curArea = stack.top().second * (i - stack.top().first); // height * width
                ans = max(ans, curArea);
                width = stack.top().first;
                stack.pop();
            }
            stack.push({ width, heights[i] });
        }
        while (!stack.empty()) {
            int curArea = stack.top().second * (heights.size() - stack.top().first); // height * width
            ans = max(ans, curArea);
            stack.pop();
        }
        return ans;
    }
};