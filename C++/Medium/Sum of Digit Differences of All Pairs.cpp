// instead of converting to strings I should have just done num % 10. I didn't do this because I was worried of 0. but the constraints don't allow for any number to be 0.
class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        vector<vector<int>> totalDigits;
        vector<string> copy;
        for (int i = 0; i < nums.size(); i++) {
            copy.push_back(to_string(nums[i]));
        }
        for (int i = 0; i < copy[0].size(); i++) {
            vector<int> digits(10, 0);
            for (int j = 0; j < nums.size(); j++) {
                digits[copy[j][i] - '0']++;
            }
            totalDigits.push_back(digits);
        }
        //    long long maxAns = ((((nums.size() - 1) * nums.size()) / 2) * copy[0].size());
        long long ans = 0;
        for (int i = 0; i < totalDigits.size(); i++) {
            for (int j = 0; j < totalDigits[i].size(); j++) {
                ans += totalDigits[i][j] * (nums.size() - totalDigits[i][j]);
            }
        }
        ans /= 2; //we've double counted.
        return ans;
    }
};