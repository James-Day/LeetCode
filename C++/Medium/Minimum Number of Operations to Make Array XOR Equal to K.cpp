class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int finalXorVal = 0;
        for (int n : nums) {
            finalXorVal ^= n;
        }
        int count = 0;
        while (k || finalXorVal) {
            if (k % 2 != finalXorVal % 2) {
                count++;
            }
            k /= 2;
            finalXorVal /= 2;
        }
        return count;
    }
};