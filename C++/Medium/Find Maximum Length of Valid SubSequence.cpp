class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int oddParityAns = 0;
        int curCheck = 0;
        bool odd = true;
        for (int j = 0; j < 2; j++) {
            if (j == 1) odd = false;
            for (int i = 0; i < nums.size(); i++) {
                if (odd && nums[i] % 2 == 1) {
                    curCheck++;
                    odd = false;
                }
                else if (!odd && nums[i] % 2 == 0) {
                    curCheck++;
                    odd = true;
                }
            }
            oddParityAns = max(oddParityAns, curCheck);
            curCheck = 0;
        }
        int evens = 0;
        int odds = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0)
                evens++;
            else
                odds++;
        }
        return max(max(oddParityAns, evens), odds); // these are the three possibilities. (evens, odds, alternating)
    }
};