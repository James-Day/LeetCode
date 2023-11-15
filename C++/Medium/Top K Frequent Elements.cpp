#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);

        for (auto i = map.begin(); i != map.end(); i++) {
            buckets[i->second].push_back(i->first);
        }

        vector<int> ans;
        int i = nums.size();
        while (ans.size() < k) {
            if (!buckets[i].empty()) {
                ans.insert(ans.end(), buckets[i].begin(), buckets[i].end());
            }
            i--;
        }
        return ans;
    }
};