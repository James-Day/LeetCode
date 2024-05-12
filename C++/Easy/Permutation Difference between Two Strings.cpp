//better solution with only one map
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> sMap;
        for (int i = 0; i < s.size(); i++) {
            sMap[s[i]] = i;
        }
        int ans = 0;
        for (int i = 0; i < t.size(); i++) {
            ans += abs(i - sMap[t[i]]);
        }
        return ans;
    }
};
//
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> sMap, tMap;
        for (int i = 0; i < s.size(); i++) {
            sMap[s[i]] = i;
            tMap[t[i]] = i;
        }
        int ans = 0;
        for (auto i = sMap.begin(); i != sMap.end(); i++) {
            ans += abs(i->second - tMap[i->first]);
        }
        return ans;
    }
};