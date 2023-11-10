class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int maxLength = max(word1.length(), word2.length());
        int word1Length = word1.length();
        int word2Length = word2.length();

        for (int i = 0; i < maxLength; i++) {
            if (i < word1Length) {
                ans += word1[i];
            }
            if (i < word2Length) {
                ans += word2[i];
            }
        }
        return ans;
    }
};