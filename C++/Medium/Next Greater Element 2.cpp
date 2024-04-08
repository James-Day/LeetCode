//O(n) run time, you can merge the two for loops but I believe that makes things seem more complicated.
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> stack;
        vector<int> ans(n, -1);
        for (int i = 0; i < n; ++i) {
            while (!stack.empty() && nums[stack.top()] < nums[i]) {
                ans[stack.top()] = nums[i];
                stack.pop();
            }
            stack.push(i);
        }
        for (int i = 0; i < n; ++i) {
            while (!stack.empty() && nums[stack.top()] < nums[i]) {
                ans[stack.top()] = nums[i];
                stack.pop();
            }
        }
        return ans;
    }
};