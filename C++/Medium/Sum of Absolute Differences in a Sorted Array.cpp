#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        vector<int> ans;
        int leftSum = 0;
        int rightSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            rightSum += nums[i]; // right sum will start at total sum
        }

        for (int i = 0; i < nums.size(); i++)
        {
            rightSum -= nums[i];
            int left = (i * nums[i]) - leftSum;
            int right = rightSum - ((nums.size() - i - 1) * nums[i]);
            ans.push_back(left + right);
            leftSum += nums[i];
        }
        return ans;
    }
};