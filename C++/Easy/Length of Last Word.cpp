//O(N) time, O(1) space
class Solution {
public:
    int lengthOfLastWord(string s) {
        int seen = -1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ' && seen == -1) seen = i;
            if (seen != -1 && s[i] == ' ') {
                return seen - i;
            }
        }
        return seen + 1;
    }
};