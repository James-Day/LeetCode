class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(nums.size() * 2, 0);

        for(int i = 0; i < nums.size() * 2; i++){
            ans[i] = nums[i% nums.size()];
        }
        return ans;
    }
};