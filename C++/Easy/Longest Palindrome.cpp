class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); i++) {
            map[s[i]]++;
        }
        int ans = s.size();
        for (auto i = map.begin(); i != map.end(); i++) {
            if (i->second % 2 == 1) {
                ans--;
            }
        }
        ans += ans != s.size();
        return ans;
    }
};