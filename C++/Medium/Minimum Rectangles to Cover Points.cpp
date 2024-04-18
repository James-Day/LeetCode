class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());
        int res = 0, endOfRectangle = -1;
        for (vector<int>& point : points)
            if (point[0] > endOfRectangle) {
                res++,
                    endOfRectangle = point[0] + w;
            }
        return res;
    }
};