#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> map;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        for (auto i = map.begin(); i != map.end(); i++) {
            ans += (((i->second - 1) * i->second) / 2); //(n-1) * (n/2)
        }
        return ans;
    }
};


