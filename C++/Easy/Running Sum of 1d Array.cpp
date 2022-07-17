class Solution {
public:
//another way to do this would be to get the number at the end of your vector and add it to the number from the input vector.
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        
        int output =0;
        for(int i =0; i < nums.size(); i++){
            output += nums[i];
            ans.push_back(output);
        }
        return ans;
    }
};