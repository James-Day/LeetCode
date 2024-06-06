class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int count = 1;
        char prev = word[0]; //anyhting but lowercase
        for (int i = 1; i < word.size(); i++) {
            if (count == 9 || prev != word[i]) {
                ans += (string(1, '0' + count) + string(1, prev));
                prev = word[i];
                count = 0;
            }
            if (prev == word[i]) count++;

        }
        ans += (string(1, '0' + count) + string(1, prev));
        return ans;
    }
};