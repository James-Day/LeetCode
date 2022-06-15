#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int num = 0; num < nums.size(); num++) {
            for (int i = num + 1; i < nums.size(); i++) {
                if (nums[num] + nums[i] == target) {
                    result.push_back(num);
                    result.push_back(i);
                    return result;
                }
            }
        }
        return result;
    }
};