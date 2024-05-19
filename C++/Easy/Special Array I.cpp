class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] % 2 == nums[i] % 2) return false; //instead of % 2 you could alos do bitwise and with 1 (& 1) to get the parity.
        }
        return true;
    }
};