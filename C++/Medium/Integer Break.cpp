#include <unordered_map>
using namespace std;
class Solution {
public:
    unordered_map<int, int> map;
    Solution() {
        map[1] = 1;
    }
    int integerBreak(int n) {
        return dfs(n, n);
    }
    int dfs(int n, int start) {
        if (map.contains(n)) {
            return map[n];
        }
        int result = 0;
        if (n != start) {
            result = n;
        }

        for (int i = 1; i < n; i++) {
            int val = dfs(i, start) * dfs(n - i, start);
            result = max(result, val);
            map[n] = result;
        }
        return map[n];
    }
};