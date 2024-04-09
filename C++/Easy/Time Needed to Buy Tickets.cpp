//O(N) time, O(N) space. Notice that all values after index k will buy 1 less ticket.
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int val = tickets[k];
        int ans = 0;
        for (int i = 0; i < tickets.size(); i++) {
            if (i <= k) {
                ans += min(val, tickets[i]);
            }
            else {
                ans += min(val - 1, tickets[i]);
            }
        }
        return ans;
    }
};