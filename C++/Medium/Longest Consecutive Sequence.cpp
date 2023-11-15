#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());

        int highestSoFar = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!seen.contains(nums[i] - 1)) {
                int j = 0;
                while (seen.contains(nums[i] + j)) {
                    j++;
                }
                highestSoFar = max(highestSoFar, j);
            }
        }
        return highestSoFar;
    }
};