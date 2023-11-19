#include <vector>
using namespace std;
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int operations = 0;
        int OperationstoEqual = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                OperationstoEqual++;
            }
            operations += OperationstoEqual;
        }

        return operations;
    }
};