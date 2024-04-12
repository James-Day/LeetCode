class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stack;
        unordered_map<int,int> map;
        for(int num : nums2){
            while(!stack.empty() && stack.top() < num){
                map[stack.top()] = num;
                stack.pop();
            }
            stack.push(num);
        }
        vector<int> res(nums1.size());
        for(int i = 0; i < nums1.size(); i++){
            res[i] = map.contains(nums1[i]) ? map[nums1[i]] : -1; // negative 1 if not found.
        }
        return res;
    }
};