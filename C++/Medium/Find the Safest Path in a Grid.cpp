//very long question. Definitally feel like it's a leetcode Hard. Also not sure where optimizations are.
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        vector<vector<int>> safestDistance(
            grid.size(), vector<int>(grid[0].size(), INT_MAX));
        vector<vector<bool>> visited(grid.size(),
            vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1)
                    q.push({ i, j });
            }
        }
        int level = 0;
        cout << q.front().first << " " << q.front().second << endl;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                pair<int, int> cur = q.front();
                if (cur.first < 0 || cur.second < 0 ||
                    cur.first >= grid.size() ||
                    cur.second >= grid[cur.first].size() ||
                    visited[cur.first][cur.second] == true) {
                    q.pop();
                    continue;
                }
                visited[cur.first][cur.second] = true;
                safestDistance[cur.first][cur.second] =
                    min(safestDistance[cur.first][cur.second], level);
                q.push({ cur.first + 1, cur.second });
                q.push({ cur.first, cur.second + 1 }); //should prob make a directions array since we do this twice.
                q.push({ cur.first - 1, cur.second });
                q.push({ cur.first, cur.second - 1 });
                q.pop();
            }
            level++;
        }
        priority_queue<pair<int, pair<int, int>>> pq;
        int ans = INT_MAX;
        pq.push({ safestDistance[0][0], {0, 0} });
        for (auto& row : visited) {
            fill(row.begin(), row.end(), false);
        }
        while (!pq.empty()) {
            pair<int, pair<int, int>> cur = pq.top();
            int i = cur.second.first;
            int j = cur.second.second;
            pq.pop();
            if (visited[i][j]) continue;
            ans = min(ans, cur.first);
            if (i == grid.size() - 1 && j == grid[i].size() - 1)
                return ans;
            visited[i][j] = true;
            if (i + 1 < grid.size()) pq.push({ safestDistance[i + 1][j], {i + 1, j} });
            if (j + 1 < grid.size()) pq.push({ safestDistance[i][j + 1], {i, j + 1} });
            if (i - 1 >= 0) pq.push({ safestDistance[i - 1][j], {i - 1, j} });
            if (j - 1 >= 0) pq.push({ safestDistance[i][j - 1], {i, j - 1} });
        }
        return ans;
    }
};