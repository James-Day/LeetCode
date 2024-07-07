class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int emptyBottles = 0;
        while (numBottles > 0) {
            ans += numBottles;
            int emptyAndFull = numBottles + emptyBottles;
            numBottles = emptyAndFull / numExchange;
            emptyBottles = emptyAndFull % numExchange;
        }
        return ans;
    }
};