class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        unordered_map<int, int> cache;
        return helper(0, books, shelfWidth, cache);
    }
    int helper(int i, vector<vector<int>>& books, int& shelfWidth, unordered_map<int, int>& cache) {
        int start = i;
        if (i == books.size()) return 0;
        if (cache.contains(start)) return cache[start];
        int curWidth = 0;
        int maxHeight = 0;
        cache[start] = INT_MAX;
        for (; i < books.size(); i++) {
            if (curWidth + books[i][0] > shelfWidth) break;
            curWidth += books[i][0];
            maxHeight = max(maxHeight, books[i][1]);

            cache[start] = min(helper(i + 1, books, shelfWidth, cache) + maxHeight, cache[start]);
        }
        return cache[start];
    }
};