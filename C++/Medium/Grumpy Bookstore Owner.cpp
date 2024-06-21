class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int maxSaved = 0;
        int curSaved = 0;
        int ans = 0;
        for (int i = 0; i < minutes; i++) {
            curSaved += grumpy[i] * customers[i];
        }
        maxSaved = curSaved;
        int i = 0;
        for (int j = minutes; j < grumpy.size(); j++) {
            curSaved -= grumpy[i] * customers[i];
            curSaved += grumpy[j] * customers[j];
            maxSaved = max(maxSaved, curSaved);
            i++;
        }
        for (int i = 0; i < customers.size(); i++) {
            ans += !grumpy[i] * customers[i];
        }
        return ans + maxSaved;
    }
};