//O(N) Time , O(1) Space. Even though there are nested loops, 
// each iterateion of the while loop ensures that a number is now 
// in its correct spot. There are only O(N) slots, so its O(N) + O(N) 
// which is still just O(N) Time complexity.
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};