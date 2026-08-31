#include <vector>
#include <unordered_map>
using namespace std;

//best time complexity solution (buckets)
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

//sorting solution
/*

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int ,int> count;

        for(int i = 0; i <nums.size(); i++){
            count[nums[i]] ++;
        }
        vector<vector> freq;

        for(auto it = count.begin(); it != count.end(); it++){
            freq.push_back({it->second, it->first});
        }

        sort(freq.rbegin(), freq.rend());
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(freq[i].second);
        }
        return res;
    }
};
*/

//heap solution
/*
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (auto& entry : count) {
            heap.push({entry.second, entry.first});
            if (heap.size() > k) {
                heap.pop();
            }
        }

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};
*/