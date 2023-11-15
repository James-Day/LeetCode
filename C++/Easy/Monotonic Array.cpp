#include <vector>
using namespace std;
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() == 1) return true;
        bool increasing = true;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                increasing = false;
            }
        }
        if (increasing) {
            return true;
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                return false;  //not strictly decreasing or increasing
            }
        }
        return true;//decreasing
    }
};