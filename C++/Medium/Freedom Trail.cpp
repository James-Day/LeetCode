class Solution {
public:
    int findRotateSteps(string ring, string key) {
        map<pair<int, int>, int> map;
        return helper(0, 0, ring, key, map);
    }
    int helper(int r, int k, string& ring, string& key, map<pair<int, int>, int>& map) {
        if (k == key.length()) {
            return 0;
        }
        if (map.contains({ r,k })) {
            return map[{r, k}];
        }
        int res = INT_MAX;
        for (int i = 0; i < ring.size(); i++) {
            if (ring[i] == key[k]) {
                int min_distance = min(abs(r - i), (int)(ring.length() - abs(r - i)));
                res = min(res, min_distance + 1 + helper(i, k + 1, ring, key, map)); //check all possible duplicate letters
            }
        }
        map[{r, k}] = res;
        return res;
    }
};