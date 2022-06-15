#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            bool buy = false;
            int profit = 0;
            if (prices[i + 1] > prices[i]) {
                buy = true;
            }
            if (buy != false) {
                profit = prices[i + 1] - prices[i];
            }
            total += profit;
        }
        return total;
    }
};