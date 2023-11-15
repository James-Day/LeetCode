#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (int i = 0; i < strs.size(); i++) {
            string original = strs[i];
            sort(strs[i].begin(), strs[i].end());
            map[strs[i]].push_back(original);
        }

        vector<vector<string>> ans;
        for (auto i = map.begin(); i != map.end(); i++) {
            ans.push_back(i->second);
        }
        return ans;
    }
};