#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:

    int reverse(int n) {
        int ans = 0;
        while (n > 0) {
            ans = ans * 10 + n % 10;
            n /= 10;
        }
        return ans;
    }

    int countNicePairs(std::vector<int>& nums) {
        unordered_map<int, long> count; //first = nums[i] - rev(nums[i]) // second equals count
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i] - reverse(nums[i])]++;
        }
        long ans = 0;
        for (auto i = count.begin(); i != count.end(); i++) {
            ans += (i->second * (i->second - 1)) / 2;
        }
        return ans % 1000000007;
    }
};