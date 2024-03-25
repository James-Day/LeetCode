/*intuition: doing the problem I kept thinking that to get this down to O(N) and constant memory that somehow I'd need to store the state within the given array.
I first thought about setting the value to zero instead of *= -1, but realized you'd have to do some sort of recursion which would end up with certain numbers
getting counted twice. Ultimately I realized that you can still add some state which is negitive(seen) or non-negative. Really cool solution!*/
//Time: O(N), Space: O(1) (but you ruin the input array)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i]) - 1] < 0) {
                ans.push_back(abs(nums[i]));
            }
            else {
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        return ans;
    }
};