// sliding window time = O(N), Space O(1) (since we have a limited number of possible characters)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int ans = 0;
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            while (seen.contains(s[r])) {
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};