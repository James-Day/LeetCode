class Solution {
public:
    int appendCharacters(string s, string t) {
        int t_index = 0;
        for (int i = 0; i < s.size(); i++) {
            if (t[t_index] == s[i]) t_index++;
        }
        return t.size() - t_index;
    }
};