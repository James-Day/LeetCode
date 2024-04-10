class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stack;
        unordered_map<int, int> map;
        for (int i = 0; i < nums2.size(); i++) {
            while (!stack.empty() && stack.top() < nums2[i]) {
                map[stack.top()] = nums2[i];
                stack.pop();
            }
            stack.push(nums2[i]);
        }
        vector<int> ans(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++) {
            if (map.contains(nums1[i])) {
                ans[i] = (map[nums1[i]]);
            }
        }
        return ans;
    }
};