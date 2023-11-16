#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = { -1,-1 };
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                res[0] = i;
                for (int j = i; j < nums.size() && nums[j] == target; j++) {
                    res[1] = j;
                }
                return res;
            }
        }
        return res;
    }
};