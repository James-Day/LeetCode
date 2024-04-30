class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int finalXorVal = 0;
        for (int n : nums) {
            finalXorVal ^= n;
        }
        int count = 0;
        while (k || finalXorVal) { //until both are zero check each bit
            if (k % 2 != finalXorVal % 2) { // 1 , 0 , or 0, 1 (i.e. bits are different)
                count++;
            }
            k /= 2;
            finalXorVal /= 2;
        }
        return count;
    }
};