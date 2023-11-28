#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ans;
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }

        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            int leftSize = i;
            int rightSize = nums.size() - leftSize - 1;
            int rightSum = totalSum - leftSum - nums[i];

            int curAns = (nums[i] * leftSize) - leftSum + rightSum - (nums[i] * rightSize);

            ans.push_back(curAns);
            leftSum += nums[i];
        }

        return ans;
    }
};