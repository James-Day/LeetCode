class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int cons = 0;
        int maxCons = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1])cons++;
            else {
                cons = 0;
            }
            maxCons = max(maxCons, cons);
        }
        return maxCons + 1;
    }
};