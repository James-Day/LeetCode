class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans;
        int actualRotate = k % nums.size();
        for(int i =(nums.size() - actualRotate); i < nums.size(); i++){
           ans.push_back(nums[i]);
        }
        for(int i =0; i < (nums.size() - actualRotate); i++){
           ans.push_back(nums[i]);
        }
        nums = ans;
    }
};