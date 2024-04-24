class Solution { //initially I used a hashmap instead of vector of pairs for the queries, but it failed to multiple queries with the same value.
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans(queries.size());
        vector<pair<int, int>> queryPair;
        for (int i = 0; i < queries.size(); i++) {
            queryPair.push_back({ queries[i], i });
        }

        sort(items.begin(), items.end());
        sort(queryPair.begin(), queryPair.end());
        int itemIndex = 0, maxBeauty = 0;
        for (int i = 0; i < queries.size(); i++) {
            while (itemIndex < items.size() && items[itemIndex][0] <= queryPair[i].first) {
                maxBeauty = max(maxBeauty, items[itemIndex][1]);
                itemIndex++;
            }
            ans[queryPair[i].second] = maxBeauty;
        }
        return ans;
    }
};