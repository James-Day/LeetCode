#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    unordered_map<int, int> map;
    int minCostClimbingStairs(vector<int>& cost) {
        return min(helper(cost, 0), helper(cost, 1));

    }
    int helper(vector<int>& cost, int i) {
        if (i >= cost.size()) {
            return 0;
        }
        if (map.contains(i)) {
            return map[i];
        }

        int a = helper(cost, i + 1);
        int b = helper(cost, i + 2);



        map[i] = min(a + cost[i], b + cost[i]);
        return min(a + cost[i], b + cost[i]);
    }
};