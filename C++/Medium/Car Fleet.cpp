#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> stack;

        for (int i = 0; i < position.size(); i++) {
            stack.push_back({ position[i], (double)(target - position[i]) / speed[i] });
        }

        sort(stack.begin(), stack.end());

        int totalFleets = 0;
        double longestTime = 0;
        while (!stack.empty()) {
            if (stack.back().second > longestTime) {
                longestTime = stack.back().second;
                totalFleets++;
            }
            stack.pop_back();
        }
        return totalFleets;

    }
};