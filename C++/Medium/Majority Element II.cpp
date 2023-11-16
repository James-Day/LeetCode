#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;

        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
            if (count.size() > 2) {
                unordered_map<int, int> newMap;
                for (auto j = count.begin(); j != count.end(); j++) {
                    if (j->second - 1 != 0) {
                        newMap.insert({ j->first, j->second - 1 });
                    }
                }
                count = newMap;
            }
        }
        vector<int> ans;
        for (auto i = count.begin(); i != count.end(); i++) {
            int realCount = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == i->first) {
                    realCount++;
                }
            }
            if (realCount > nums.size() / 3) {
                ans.push_back(i->first);
            }
        }
        return ans;
    }
};