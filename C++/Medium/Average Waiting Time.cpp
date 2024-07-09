class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long chefsTime = customers[0][0];
        long long totalWaitingTime = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (chefsTime < customers[i][0]) chefsTime = customers[i][0];
            chefsTime += customers[i][1];
            totalWaitingTime += chefsTime - customers[i][0];
        }
        return (double)totalWaitingTime / customers.size();
    }
};