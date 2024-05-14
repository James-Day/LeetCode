class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        unordered_map<char, vector<pair<int, int>>> map;

        for (int i = 0; i < s.size(); i++) {
            map[s[i]].push_back({ points[i][0], points[i][1] });
        }
        int closestColision = INT_MAX;
        for (auto i = map.begin(); i != map.end(); i++) {
            int minColision = INT_MAX;
            int minColision2 = INT_MAX;
            if (i->second.size() > 1) {
                //collision
                for (int j = 0; j < i->second.size(); j++) {
                    int squareSize = max(abs(i->second[j].first), abs(i->second[j].second));
                    if (squareSize < minColision) {
                        minColision2 = minColision;
                        minColision = squareSize;;
                    }
                    else if (squareSize < minColision2) {
                        minColision2 = squareSize;
                    }
                }
            }
            closestColision = min(minColision2, closestColision);
        }
        // now check every point to see if its in (closestColision -1) * (closestColision -1)
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            if (abs(points[i][0]) < closestColision && abs(points[i][1]) < closestColision) ans++;
        }
        return ans;
    }
};