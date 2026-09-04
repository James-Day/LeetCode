// https://leetcode.com/problems/product-of-array-except-self/
#include <vector>
using namespace std;

// Prefix & Suffix product solution (O(1) extra space, no division)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        int pre = 1;
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = pre;
            pre *= nums[i];
        }

        int post = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans[i] *= post;
            post *= nums[i];
        }
        return ans;
    }
};

// Division with zero-handling solution
/*
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.empty()) return {};

        int zeroCount = 0;
        int totalWithoutZero = 1;

        for(int num: nums){
            if (num == 0) {
                zeroCount++;
            } else {
                totalWithoutZero *= num;
            }
        }

        vector<int> ans(nums.size(), 0);

        // return all zeros if more than 2 zeros
        if (zeroCount >= 2) {
            return ans;
        }

        for(int i = 0; i < nums.size(); i++){
             if (nums[i] == 0) {
                ans[i] = totalWithoutZero;           
            } else if (zeroCount == 0) {
                ans[i] = totalWithoutZero / nums[i]; //can't be zero, so division is fine
            }
        }
        return ans;
    }
};
*/