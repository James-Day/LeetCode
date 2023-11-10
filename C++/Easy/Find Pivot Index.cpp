#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }
        int sumSoFar = 0;
        for (int i = 0; i < nums.size(); i++) {

            if (sumSoFar * 2 == totalSum - nums[i]) {
                return i;
            }

            sumSoFar += nums[i];
        }
        return -1;
    }
};